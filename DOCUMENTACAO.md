# AquaAlert — Documentação técnica e revisão do firmware

Este documento descreve o que o firmware do AquaAlert faz, como as partes se
encaixam, como compilar e gravar, e o resultado de uma revisão do código
inteiro (problemas encontrados e sugestões de correção).

---

## 1. Visão geral

O AquaAlert é uma rede de **placas que trocam um alerta por rádio sub-GHz
(915–928 MHz) com criptografia de ponta a ponta**. O rádio é configurado para
o **maior alcance que o hardware permite** (~+27 dBm com o FEM, camada física
de alta sensibilidade), com **salto de frequência** em 50 canais (§6).

- Ao apertar o botão **B1 (USER)** de uma placa, ela envia o comando `0xAA`
  para **cada uma das outras placas** da rede, uma vez em cada canal.
- Cada mensagem é **cifrada e autenticada** com uma chave exclusiva do par
  origem→destino, derivada por **ECDH X25519**. A cifra é **XSalsa20-Poly1305**.
- A placa que recebe um comando autêntico **inverte o estado do LED LD2**.
- Quadros de placas desconhecidas, adulterados, destinados a outra placa ou
  repetidos (replay) são descartados.

Hoje a rede tem **2 nós** (`NODE_ID` 1 e 2). O mesmo código-fonte serve para
todas as placas; só muda o `NODE_ID` na compilação.

---

## 2. Hardware

| Item | Descrição |
| --- | --- |
| Placa principal | **NUCLEO-L476RG** (STM32L476RG, Cortex-M4F, 1 MB flash, 96 KB SRAM1 + 32 KB SRAM2) |
| Shield de rádio | **X-NUCLEO-S2915A1** (transceptor **S2-LP** + FEM **Skyworks SKY66420**, banda 915 MHz) |
| Clock | HSI 16 MHz → PLL (M=1, N=10, R=2) → **80 MHz** SYSCLK, latência de flash 4 WS ([Src/system_clock.c](Src/system_clock.c)) |
| Programação/depuração | ST-Link embarcado da Nucleo (SWD) |

### Pinos

| Pino | Função |
| --- | --- |
| PA5 | LED LD2 (saída) |
| PC13 | Botão B1/USER, EXTI13 borda de descida → `EXTI15_10_IRQHandler` |
| PB3 / PA6 / PA7 | SPI1 SCK / MISO / MOSI (S2-LP) |
| PA1 | CS do S2-LP (GPIO, NSS por software) |
| PA8 | SDN (shutdown) do S2-LP |
| PC0 | GPIO3 do S2-LP (linha de IRQ), EXTI0 borda de descida → `EXTI0_IRQHandler` |
| PA0 / PA4 / PB0 | CSD / CPS / CTX do FEM SKY66420 (TX: PA ligado; RX: LNA ligado), acionados por `S2LPCmdStrobeTx()` / `S2LPCmdStrobeRx()` |

SPI1: master, full-duplex, 8 bits, MSB first, CPOL=0/CPHA=0, prescaler 4 (20 MHz).

---

## 3. Estrutura do repositório

| Caminho | Conteúdo | Origem |
| --- | --- | --- |
| [Src/main.c](Src/main.c) | Aplicação: inicialização, laço principal, TX/RX do alerta | **Projeto** |
| [Src/secure_link.c](Src/secure_link.c) / [Inc/secure_link.h](Inc/secure_link.h) | Enlace seguro: formato do quadro, contadores, anti-replay, contador de boot em flash | **Projeto** |
| [Src/ecc_crypto.c](Src/ecc_crypto.c) / [Inc/ecc_crypto.h](Inc/ecc_crypto.h) | X25519, HSalsa20/XSalsa20, Poly1305, auto-teste (derivado do TweetNaCl) | **Projeto** |
| `Inc/ecc_keys.h` | Chaves privadas e públicas dos nós (**gerado, fora do git**) | **Projeto** |
| [Inc/ecc_keys.example.h](Inc/ecc_keys.example.h) | Modelo sem segredos do arquivo de chaves | **Projeto** |
| [Tools/gerar_chaves_ecc.py](Tools/gerar_chaves_ecc.py) / [Tools/gerar_chaves_ecc.c](Tools/gerar_chaves_ecc.c) | Geradores de `ecc_keys.h` para o PC (Python sem dependências ou C) | **Projeto** |
| [Inc/aquaalert_rf.h](Inc/aquaalert_rf.h) | Todos os parâmetros de RF: potência, camada física, salto de frequência | **Projeto** |
| [Src/fhss.c](Src/fhss.c) / [Inc/fhss.h](Inc/fhss.h) | Salto de frequência: tabela de canais, sorteio, controle de ocupação por canal | **Projeto** |
| [Src/stm32l4xx_it.c](Src/stm32l4xx_it.c) | Handlers de SysTick, EXTI0 e EXTI15_10 | **Projeto** |
| [Src/system_clock.c](Src/system_clock.c) | Configuração de clock 80 MHz | **Projeto** |
| [Src/s2lp_interface.c](Src/s2lp_interface.c) | Camada de interface do S2-LP (init do shield, FEM, TX/RX) | ST (adaptado) |
| [Src/radio_appli.c](Src/radio_appli.c) / [Inc/radio_appli.h](Inc/radio_appli.h) | Exemplo P2P original da ST. **Quase todo sem uso**; só fornece macros de configuração e `HAL_GPIO_EXTI_Callback` | ST |
| [Inc/stm32l4xx_hal_conf.h](Inc/stm32l4xx_hal_conf.h) | Módulos HAL habilitados (GPIO, RCC, FLASH, PWR, SPI, TIM, DMA, CORTEX) | Projeto |
| [Src/syscalls.c](Src/syscalls.c), [Src/sysmem.c](Src/sysmem.c), [Src/system_stm32l4xx.c](Src/system_stm32l4xx.c), [Startup/startup_stm32l476rgtx.s](Startup/startup_stm32l476rgtx.s) | Suporte de runtime, `_sbrk`, `SystemInit`, tabela de vetores | ST/CubeIDE |
| [STM32L476RGTX_FLASH.ld](STM32L476RGTX_FLASH.ld) | Linker script (flash reduzida a 1020 KB, ver §7.4) | CubeIDE (modificado) |
| `Drivers/STM32L4xx_HAL_Driver` | HAL do STM32L4 | ST |
| `Drivers/BSP/STM32L4xx_Nucleo` | LED/botão da Nucleo | ST |
| `Drivers/BSP/X-NUCLEO-S2868A1` | SPI, GPIO, EEPROM e timer do shield (serve também ao S2915A1) | ST |
| `Drivers/BSP/Components/S2LP` | Biblioteca do S2-LP + utilitários (identificação da placa, offset de frequência) | ST |
| `CMSIS/` | CMSIS Core e device headers (DSP/NN/RTOS presentes mas **não compilados**) | ARM/ST |
| [CONFIGURACAO_HARDWARE.md](CONFIGURACAO_HARDWARE.md) | Notas de hardware e procedimento de gravação | Projeto |
| [Src/stm32l4xx_it_PATCH.txt](Src/stm32l4xx_it_PATCH.txt) | Instruções antigas para editar o `stm32l4xx_it.c` gerado pelo CubeIDE. Já aplicadas; arquivo obsoleto | Projeto |

---

## 4. Compilação e gravação

### 4.1 PlatformIO

Arquivos: [platformio.ini](platformio.ini) e [pio_fpu.py](pio_fpu.py).

- O projeto não usa framework do PlatformIO (`framework` ausente). HAL, CMSIS, startup e
  linker script vêm do próprio repositório, como no CubeIDE.
- `src_dir = .` e `build_src_filter` selecionam exatamente as pastas que o
  CubeIDE compila (`Src`, `Startup`, `Drivers/...`).
- Defines iguais ao `.cproject`: `STM32L476xx`, `USE_STM32L4XX_NUCLEO`,
  `X_NUCLEO_S2915A1`, `DEBUG` etc.
- O toolchain é fixado em **GCC 12.3** (`toolchain-gccarmnoneeabi@~1.120301.0`),
  porque o linker script do CubeIDE usa a palavra-chave `(READONLY)`, que exige GCC ≥ 11.
- `pio_fpu.py` acrescenta `-mfpu=fpv4-sp-d16 -mfloat-abi=hard` (como no CubeIDE)
  em compilação, assembler e link, além de `--specs=nano.specs`,
  `--gc-sections` e `-fno-use-linker-plugin`. A última flag contorna uma falha
  ao carregar `liblto_plugin.dll` nesta máquina Windows. O projeto não usa LTO.
- Há uma env por placa: **`node1`** (`-DNODE_ID=1`) e **`node2`** (`-DNODE_ID=2`).

```powershell
$pio = "$env:USERPROFILE\.platformio\penv\Scripts\pio.exe"
& $pio run -e node1              # compila a placa 1
& $pio run -e node1 -t upload    # grava a placa 1 (ST-Link)
& $pio run -e node2 -t upload    # grava a placa 2
& $pio debug -e node1            # depuração (ou F5 no VS Code)
```

Resultado atual: RAM 808 B (0,8 %), Flash ~23,8 KB (2,3 %) por nó.

Observação: o PlatformIO compila em modo *release* (`-Os`), enquanto o CubeIDE
usa `-O0` no Debug. O [ecc_crypto.c](Src/ecc_crypto.c) força `-O2` via
`#pragma` nos dois casos.

### 4.2 STM32CubeIDE

O projeto original (`.project`, `.cproject`, `AquaAlert Debug.launch`)
continua funcionando. Ali o `NODE_ID` é definido em `Inc/ecc_keys.h` ou em
*Properties > C/C++ Build > Settings > Preprocessor*.

---

## 5. Fluxo de execução

### 5.1 Inicialização ([Src/main.c:100-145](Src/main.c#L100-L145))

1. `HAL_Init()` configura o SysTick de 1 ms e o NVIC.
2. `SystemClock_Config()` coloca o clock em 80 MHz a partir do HSI + PLL.
3. Habilita os clocks de GPIOA/B/C.
4. `BSP_LED_Init(LED2)` e `BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_EXTI)` configuram
   o LED e o botão com interrupção.
5. **Segurança** (com o LD2 aceso): `SL_Init()`:
   - roda `ecc_self_test()` (vetores do RFC 7748, NaCl e RFC 8439);
   - calcula por X25519 + HSalsa20 a chave simétrica com cada outro nó;
   - avança e grava em flash o **contador de boot** (§7.4).
   - Se algo falhar, vai para `SecurityFault()`: o rádio nunca é usado e o LD2
     pisca **N vezes, pausa 1,5 s, repete**, onde N = 1 (auto-teste), 2
     (chave) ou 3 (flash).
6. `S2LPInterfaceInit()` ([Src/s2lp_interface.c](Src/s2lp_interface.c)):
   - configura o pino SDN, inicializa o SPI1 e o SPI da EEPROM do shield;
   - reinicia o S2-LP (shutdown → ativo);
   - `S2LPManagementIdentificationRFBoard()` lê a EEPROM do shield (banda,
     offset de cristal, tipo de FEM);
   - **`FORCE_FEM_SKY66420`** força o uso do FEM SKY66420 mesmo que a EEPROM
     não seja lida;
   - configura os GPIOs do FEM e a linha de IRQ (GPIO3 → PC0, EXTI0,
     prioridade 3).
   Antes do rádio, `FHSS_Init()` embaralha a tabela de canais com uma semente
   tirada do ID único do chip e do contador de boot, para que cada placa use
   uma sequência diferente.
7. Grava em `gRangeExt` e `gHasEeprom` o resultado da identificação, para diagnóstico.
8. Ajusta a frequência base (915,375 MHz) com o offset da EEPROM.
9. `RadioInitAll()` ([Src/main.c:242](Src/main.c#L242)) configura o rádio (§6)
   e as IRQs `RX_DATA_READY`, `RX_DATA_DISC`, `RX_TIMEOUT`, `TX_DATA_SENT` e
   `MAX_BO_CCA_REACH`.
10. `ParkOnNewChannel()` sorteia o canal de escuta e coloca o rádio em recepção contínua nele.

### 5.2 Laço principal ([Src/main.c:147-187](Src/main.c#L147-L187))

O laço não usa RTOS nem modo de baixo consumo. Tarefas por *polling*:

| Condição | Ação |
| --- | --- |
| Borda do botão (ISR grava `gButtonPressed` e `gButtonTick`) | `ProcessButton()`: com *debounce*, marca um alerta pendente |
| Alerta pendente e `FHSS_SweepAllowed()` | `TransmitTrigger()` (varredura em todos os canais) e volta a RX. Se a janela de ocupação não permitir, o alerta espera, sem se perder |
| `gRadioIrq` (setado pela ISR do PC0) | `HandleRadioIrq()` |
| A cada **10 min** | `ParkOnNewChannel()`: troca o canal de escuta |
| A cada **250 ms** | `HandleRadioIrq()` (caso uma IRQ tenha sido perdida), lê o estado do S2-LP e, se não estiver em RX, recoloca em RX (`gRxRearm++`) |

**Debounce** ([Src/main.c:193](Src/main.c#L193)): uma borda só vale se o botão
estava "armado". Depois de aceita, o botão só rearma quando fica solto por
150 ms. Repiques ao apertar e ao soltar, inclusive os que chegam durante a
varredura, são ignorados. Isso resolve o item 9.3.

As ISRs ([Src/stm32l4xx_it.c](Src/stm32l4xx_it.c)) só levantam flags. Todo
acesso SPI ao rádio acontece no laço principal, então não há disputa pelo
barramento.

### 5.3 Transmissão ([Src/main.c:318-386](Src/main.c#L318-L386))

`TransmitTrigger()` registra a ocupação de canal do alerta
(`FHSS_RecordSweep`) e, para cada nó `dst` diferente do próprio:

1. `SL_Seal()` monta o quadro cifrado **uma única vez** (29 bytes para 1 byte
   de comando). Todas as cópias são idênticas, com o mesmo contador e o mesmo
   nonce. Isso não enfraquece a cifra, porque o texto é o mesmo.
2. Sorteia um ponto de partida e percorre os **50 canais** na ordem
   embaralhada. Em cada canal, `TransmitOnChannel()`:
   - `RadioToReady()` (SABORT, até 5 ms) e `S2LPRadioSetChannel(canal)`;
   - define o tamanho do payload e limpa as IRQs;
   - `S2LP_StartTx()` liga o **CSMA** (limiar −90 dBm, até 5 backoffs),
     carrega a FIFO e transmite. O strobe de TX coloca o FEM em modo PA;
   - faz polling por até **600 ms** esperando `TX_DATA_SENT` (`gTxOk++`) ou
     `MAX_BO_CCA_REACH` (canal ocupado: pula o canal, `gTxFail++`).
3. No fim, volta para READY e restaura a configuração de RX (`ConfigureRxPath()`), que o CSMA altera.

Uma varredura leva cerca de **7–8 s por destino** (50 × ~145 ms). Durante esse
tempo o nó não recebe. Não existe ACK: se o destino não receber nenhuma cópia,
o alerta se perde (§9.6).

### 5.4 Recepção ([Src/main.c:388-424](Src/main.c#L388-L424))

O nó fica escutando o canal `gParkChannel`, com o FEM em modo LNA. Ele recebe
a cópia que o transmissor envia nesse canal. Se ele trocar de canal no meio de
uma varredura e ouvir uma segunda cópia, ela é recusada como repetida
(`SL_ERR_REPLAY`), e o LED não alterna duas vezes.

1. Em `RX_DATA_READY`, `S2LP_GetRxPacket()` lê todos os bytes da FIFO RX
   (buffer de 128 bytes, o tamanho da FIFO).
2. `SL_Open()` valida e decifra. Se `SL_OK` e o primeiro byte for `0xAA`, o LD2
   alterna. Os contadores `gRxOk`/`gRxRejected` e `gLastRxStatus` são
   atualizados, e `gLastRssi` guarda o RSSI do quadro.
3. O texto claro é apagado da pilha (`ecc_wipe`) e o rádio volta a RX.
4. Em `RX_DATA_DISC` ou `RX_TIMEOUT`, o rádio volta a RX.

---

## 6. Rádio: alcance máximo e salto de frequência

Todos os parâmetros ficam em [Inc/aquaalert_rf.h](Inc/aquaalert_rf.h) e são
aplicados em `RadioInitAll()` / `ConfigureRxPath()`. O CSMA ainda usa os
valores de [Inc/radio_appli.h](Inc/radio_appli.h).

### 6.1 Configuração

| Parâmetro | Antes | Agora |
| --- | --- | --- |
| Potência na antena | ~+12 dBm (`PA_POWER8 = 0x25` → −4 dBm no FEM + 16 dB) | **~+27 dBm** (S2-LP +12 dBm → FEM +16 dB, saturação) |
| Modulação | 2-FSK 38,4 kbps, desvio 20 kHz | **2-GFSK (BT=1) 4,8 kbps**, desvio 4,8 kHz |
| Filtro de RX | 100 kHz | **60 kHz** |
| FEC | desligado | **ligado** (convolucional, taxa 1/2) |
| Preâmbulo | 4 bytes | **8 bytes** (mais tempo para AFC e sincronismo de clock) |
| CRC | 8 bits | **16 bits** |
| Frequência | 915,0 MHz fixo | **50 canais** de ~248,7 kHz, 915,375 a ~927,56 MHz |
| Tempo no ar por quadro de 29 bytes | ~8 ms | ~133 ms (estimativa com margem: 165 ms) |

O restante não mudou: sync de 32 bits `0x88888888`, whitening ligado, RX
persistente com CS blanking e limiar −120 dBm, sem timeout de RX. O CSMA no TX
continua com limiar −90 dBm, período de 64 bits, CCA 3, até 5 backoffs e prescaler 32.

### 6.2 Por que esses valores (balanço de enlace)

- **Potência:** o SKY66420-11 tem ganho de TX de 16 dB e satura em +27 dBm. O
  limite absoluto na entrada TX é +17 dBm, e o S2-LP não passa de +14 dBm, então
  nenhuma configuração do S2-LP danifica o FEM. O código antigo entregava −4 dBm
  ao FEM, desperdiçando ~15 dB. **Este é o maior ganho de alcance.**
- **Sensibilidade:** reduzir a taxa de 38,4 para 4,8 kbps e o filtro de 100
  para 60 kHz, mais o ganho de codificação do FEC, deve render algo como 8 a
  12 dB. O LNA do FEM (ganho 18 dB, NF ~2 dB) já era usado em RX.
- **Por que o filtro não é mais estreito:** a placa usa **cristal de 50 MHz
  (NX1612SA), não TCXO**. O erro de frequência entre duas placas pode chegar a
  ~±20 ppm (±18 kHz em 915 MHz). O filtro de 60 kHz cobre o sinal (~15 kHz)
  mais esse erro, e o AFC (ligado por padrão no S2-LP) corrige o resto durante
  o preâmbulo. Se `gHasEeprom = 1` (offset de cada placa calibrado pela
  EEPROM), dá para cair para ~30 kHz e ganhar mais ~3 dB.
- **Estimativa total:** ~15 dB a mais de potência e ~10 dB a mais de
  sensibilidade, cerca de **25 dB a mais de balanço de enlace**. Em espaço
  livre isso multiplica o alcance por ~18. Com obstáculos e terreno (expoente
  de perda ~3–4), o ganho fica entre 4 e 7 vezes. **São estimativas: meça em
  campo** com `gLastRssi`, `gRxOk` e `gTxFail`.
- **Custo:** cada quadro fica ~16× mais longo, e cada alerta passa a ser 50
  cópias (~7–8 s por destino). Para um botão de alerta, a troca vale a pena.

### 6.3 Salto de frequência e regras (ANATEL Ato 14448 / FCC 15.247)

Para sistemas com banda de 20 dB menor que 250 kHz em 915–928 MHz:

| Requisito | Como o firmware atende |
| --- | --- |
| ≥ 50 canais | 50 canais (`#error` de compilação se for menos) |
| Espaçamento ≥ banda de 20 dB | ~248,7 kHz contra ~20 kHz de banda ocupada |
| Uso equilibrado dos canais, sequência pseudoaleatória | Cada alerta usa todos os 50 canais uma vez, em ordem embaralhada por placa |
| Ocupação ≤ 0,4 s por canal a cada 20 s | `FHSS_SweepAllowed()` soma o tempo no ar por canal das varreduras dos últimos 20 s. Com 2 nós, cabem 2 alertas a cada 20 s; um terceiro espera (`gSweepDeferred`) |
| Potência conduzida ≤ 1 W (30 dBm) | ~+27 dBm |
| Antena ≤ 6 dBi sem reduzir potência | Com antena maior, reduzir `AA_FEM_DRIVE_DBM` na mesma medida |
| Faixa | Só 915–928 MHz. A faixa 902–907,5 MHz, também permitida no Brasil, não é usada |

**Limites desta abordagem:**

- O receptor não salta em sincronia com o transmissor. Ele fica num canal e
  troca a cada 10 minutos. A regra pede receptores que acompanhem o salto. Esse
  modelo assíncrono é comum em dispositivos simples, mas para homologação
  formal é preciso confirmar a interpretação com um laboratório certificado.
- Um alerta pode se perder se o receptor trocar de canal no meio de uma
  varredura e cair num canal já varrido. A chance é de ~0,6 % por alerta, e
  `AA_FHSS_PARK_MS` controla esse número.
- A ocupação cresce com o número de nós, porque cada destino recebe uma
  varredura própria. Com 3 nós ainda cabe 1 alerta a cada 20 s. **Acima de ~3
  nós, convém trocar para uma mensagem em broadcast com chave de grupo.**
- A potência real depende também da tensão do SMPS do S2-LP (não alterada).
  Vale medir a saída com um analisador de espectro ou medidor de potência.

---

## 7. Segurança

### 7.1 Primitivas ([Src/ecc_crypto.c](Src/ecc_crypto.c))

- **X25519** (RFC 7748): escada de Montgomery em tempo constante sobre
  GF(2²⁵⁵−19), com 16 limbs de 16 bits. O resultado zero (chave pública de
  ordem baixa) é rejeitado.
- **Chave do par**: `HSalsa20(X25519(priv, pub_par), 0)`, igual a
  `crypto_box_beforenm` do NaCl. Os dois nós chegam à mesma chave.
- **XSalsa20-Poly1305** (`crypto_secretbox`): os 32 primeiros bytes do fluxo
  formam a chave Poly1305 de uso único e o restante cifra os dados. A etiqueta
  (16 bytes) é verificada em tempo constante **antes** de decifrar.
- `ecc_wipe` apaga buffers sensíveis via ponteiro `volatile`.
- `ecc_self_test()` roda a cada boot.
- Custo: algumas centenas de ms por X25519 (só no boot); cifrar um quadro leva microssegundos.

A implementação confere com o TweetNaCl. O auto-teste cobre X25519+HSalsa20,
Poly1305, ida e volta com mais de um bloco e detecção de adulteração.

### 7.2 Formato do quadro ([Inc/secure_link.h](Inc/secure_link.h))

```
 0     1     2       3        4 .. 11                 12 .. 12+n-1   12+n .. 12+n+15
[EC] [01] [origem] [destino] [contador LE, 64 bits]   [dados cifr.]  [etiqueta Poly1305]
```

- Contador = `(contador_de_boot << 32) | contador_de_mensagem`.
- **Nonce (24 bytes) = os 12 bytes do cabeçalho + 12 zeros.** Como o nonce
  inclui origem, destino e contador, alterar qualquer byte do cabeçalho
  invalida a etiqueta. A→B e B→A usam a mesma chave, mas os nonces diferem
  porque a origem faz parte deles.
- Tamanho: `12 + n + 16` bytes, com n de 1 a 32. O alerta usa n = 1, ou seja, 29 bytes.

### 7.3 Validação na recepção (`SL_Open`, [Src/secure_link.c:233](Src/secure_link.c#L233))

Ordem das verificações:

1. tamanho e magic/versão (`SL_ERR_FORMAT`);
2. destino = este nó (`SL_ERR_NOT_FOR_ME`);
3. origem válida e diferente do próprio (`SL_ERR_UNKNOWN_PEER`);
4. contador maior que o último aceito daquela origem (`SL_ERR_REPLAY`);
5. etiqueta Poly1305 (`SL_ERR_AUTH`).

A janela anti-replay só avança depois que a etiqueta é validada, então um
atacante não consegue "envenenar" o contador. O último contador aceito fica
**só em RAM** e volta a 0 quando a placa reinicia (limitação documentada no
CONFIGURACAO_HARDWARE.md).

### 7.4 Contador de boot em flash

- Ocupa as 2 últimas páginas de 2 KB do banco 2 (0x080FF000–0x080FFFFF). O
  linker script reduz a flash para 1020 KB para não sobrescrevê-las.
- Cada boot grava um registro de 64 bits `valor | ~valor << 32`. A leitura
  procura o maior valor válido nas duas páginas e grava valor+1 no próximo slot
  livre.
- Quando a página atual enche (256 boots), a outra página é apagada e passa a
  ser usada. O valor mais alto continua preservado até a gravação nova ser
  conferida.
- Esse contador garante que o nonce nunca se repita entre reinicializações,
  requisito obrigatório do XSalsa20-Poly1305.

### 7.5 Chaves (`Inc/ecc_keys.h`, [Tools/gerar_chaves_ecc.py](Tools/gerar_chaves_ecc.py))

- `Inc/ecc_keys.h` **não é versionado** (está no `.gitignore`). O repositório
  tem só o modelo [Inc/ecc_keys.example.h](Inc/ecc_keys.example.h). O arquivo
  real deve ir para as outras pessoas da equipe por um canal seguro.
- Geradores para o PC:
  - [Tools/gerar_chaves_ecc.py](Tools/gerar_chaves_ecc.py): Python 3 sem
    dependências, usa `secrets`. Antes de gerar, valida o próprio X25519 com os
    vetores do RFC 7748;
  - [Tools/gerar_chaves_ecc.c](Tools/gerar_chaves_ecc.c): C, usa `rand_s` no
    Windows e `/dev/urandom` nos outros.
  - Os dois aplicam o *clamping* do X25519 e calculam as chaves públicas.
- O header contém **as chaves privadas de todos os nós**, selecionadas por
  `#if NODE_ID == n`. Cada firmware embute só a sua privada, mas o arquivo-fonte
  tem todas.
- Para adicionar ou revogar um nó, é preciso gerar chaves novas e regravar todas as placas.

---

## 8. Diagnóstico pelo depurador

O firmware não tem UART nem printf. Para acompanhar o funcionamento, observe
estas variáveis globais em *Live Expressions* (CubeIDE) ou *Watch*
(PlatformIO/VS Code):

| Variável | Significado |
| --- | --- |
| `gSlInitStatus` | Resultado de `SL_Init()` (enum `SL_Status`) |
| `gSlSelfTestCode` | Retorno de `ecc_self_test()` (0 = OK; −1..−5 = qual teste falhou) |
| `gSlFlashStep` / `gSlFlashError` | Passo da gravação do contador de boot que falhou (1 apagar, 2 gravar, 3 conferir) e código de erro da HAL |
| `gSlBootCounter` | Contador de boot atual |
| `gTxOk` / `gTxFail` | Quadros enviados / não enviados (canal ocupado ou timeout) |
| `gRxOk` / `gRxRejected` / `gLastRxStatus` | Quadros aceitos / recusados / motivo da última recusa |
| `gRxRearm` | Vezes que o rádio foi encontrado fora de RX e recolocado |
| `gSweeps` / `gSweepDeferred` | Alertas enviados / alertas que esperaram a janela de ocupação do canal |
| `gParkChannel` | Canal (0..49) em que o nó está escutando |
| `gLastRssi` | RSSI do último quadro aceito, medido na entrada do S2-LP (inclui os ~18 dB do LNA do FEM). Útil para medir a margem em testes de alcance |
| `gRangeExt` | 3 = SKY66420 em uso; 0 = sem FEM |
| `gHasEeprom` | 1 = EEPROM do shield lida; 0 = não lida |

---

## 9. Revisão do código — problemas encontrados

Os itens estão em ordem de gravidade. Nenhum deles impede a compilação; os
dois primeiros afetam segurança ou funcionamento em campo.

### 9.1 [ALTA → CORRIGIDO] Chaves privadas versionadas no git

`Inc/ecc_keys.h` estava no repositório do GitHub (commit inicial), embora o
próprio arquivo diga "NAO versionar/compartilhar".

**Feito (2026-11-03):** chaves novas geradas, arquivo no `.gitignore`, removido
do índice do git, modelo `Inc/ecc_keys.example.h` versionado no lugar. As
chaves antigas estão **comprometidas** e não valem mais: placas gravadas com
elas não conversam com as novas. Enquanto o histórico do GitHub não for
reescrito, as chaves antigas continuam visíveis no commit inicial. Elas já não
servem para nada, mas a reescrita remove o rastro.

### 9.2 [ALTA] Reuso de nonce se a flash for apagada por inteiro

O contador de boot fica na flash. Se uma placa passar por um *mass erase*
(STM32CubeProgrammer "Full chip erase", mudança de RDP, `st-flash erase`) **sem
trocar as chaves**, o contador volta a 1. A placa então repete nonces já
usados com a mesma chave. Com XSalsa20-Poly1305, isso expõe o XOR dos textos
claros e a chave Poly1305 de uso único, o que permite forjar mensagens.
Consequência prática imediata: o outro nó, se não reiniciar, recusa os quadros
como *replay* (`SL_ERR_REPLAY`) até ser reiniciado.

A gravação normal (`pio run -t upload`, OpenOCD; ou o "Run/Debug" do CubeIDE)
apaga só os setores do firmware e **preserva** o contador.

**Correção (escolher uma):** regenerar as chaves sempre que houver mass erase
(procedimento), ou incluir no nonce um valor aleatório por boot. O STM32L476
tem **RNG em hardware**: daria para gerar 8 bytes aleatórios no boot e
colocá-los nos 12 bytes hoje zerados do nonce, transmitindo-os no quadro.

### 9.3 [MÉDIA → CORRIGIDO] Botão sem *debounce*: alerta duplicado anula o efeito

**Feito:** `ProcessButton()` em [Src/main.c](Src/main.c) (ver §5.2). Texto original do problema:

[Src/stm32l4xx_it.c:18-22](Src/stm32l4xx_it.c#L18-L22) seta `gButtonPressed` a
cada borda de descida do PC13, sem filtro. O repique mecânico, inclusive ao
soltar o botão, gera várias bordas. Se uma delas chegar durante ou depois do
`TransmitTrigger()` (≈10 ms por quadro), o laço envia o alerta **de novo**.
Como o receptor **alterna** o LED, dois alertas seguidos deixam o LED como
estava, e o alerta parece não ter chegado.

**Correção:** em `main`, ignorar o botão por ~200 ms após um envio (comparando
`HAL_GetTick()`) e/ou fazer o receptor **acender** o LED (ou acender por X
segundos) em vez de alternar.

### 9.4 [MÉDIA] Erro de ECC na flash no boot pode travar a placa

O STM32L4 tem ECC na flash. Se faltar energia **durante** a gravação do
contador de boot (no início de cada boot), o double-word pode ficar com erro de
ECC duplo. A leitura desse slot em `BootCounterAdvance()`
([Src/secure_link.c:107-124](Src/secure_link.c#L107-L124)) gera uma **NMI**. O
`NMI_Handler` é o `Default_Handler` do startup (laço infinito). Resultado: a
placa trava **em todo boot**, com o LD2 aceso, até alguém apagar a flash, o que
por sua vez cai no problema 9.2.

**Correção:** implementar `NMI_Handler` que, se `FLASH->ECCR & FLASH_ECCR_ECCD`,
limpe o flag, marque o slot como inválido e retorne. Outra opção é apagar a
página afetada e usar a outra.

### 9.5 [MÉDIA] Sem watchdog e sem handlers de falha

Não há IWDG, e `HardFault_Handler`/`NMI_Handler` caem no `Default_Handler` (laço
infinito, sem sinalização). Num dispositivo de alerta, um travamento silencioso
deixa o nó fora da rede sem ninguém perceber.

**Correção:** habilitar o IWDG (ex.: 2 s) e alimentá-lo no laço principal
(depois do `SL_Init`, que demora alguns segundos), além de um `HardFault_Handler`
que pisque um código no LD2 ou reinicie a placa.

### 9.6 [BAIXA] Sem confirmação de entrega

O envio é *fire-and-forget*: não há ACK, retransmissão nem indicação no
transmissor. `gTxFail` só registra falha de CSMA, não perda no ar. Para um
sistema de alerta, vale considerar ACK cifrado (o `SL_Seal`/`SL_Open` já
suportam payloads de até 32 bytes) e um retorno visual no transmissor.

Com o salto de frequência, um ACK também permitiria **encerrar a varredura
cedo**: o transmissor escuta uma janela curta depois de cada cópia e para ao
receber o ACK do destino. A latência média cairia pela metade, e o pior caso
aumentaria por causa das janelas de escuta.

### 9.7 [BAIXA] Pontos a conferir

- **Clock do SPI = 20 MHz** (80 MHz / 4, em `radio_spi.c`). O datasheet do
  S2-LP especifica SPI de até **10 MHz**. O valor veio do BSP da ST e funciona
  na prática, mas está fora da especificação. Usar `SPI_BAUDRATEPRESCALER_8`
  (10 MHz) é mais seguro.
- **`HAL_PWREx_ControlVoltageScaling` sem `__HAL_RCC_PWR_CLK_ENABLE()`**
  ([Src/system_clock.c:16](Src/system_clock.c#L16)): sem o clock do PWR, a
  escrita não tem efeito. Hoje não causa dano, porque o reset já deixa o
  regulador no Range 1, mas o código não faz o que parece.
- **Pilha mínima de 1 KB** no linker (`_Min_Stack_Size = 0x400`), enquanto o
  `ecc_crypto.c` declara usar ~1,5 KB. Hoje não há estouro (a pilha cresce
  sobre os ~95 KB livres), mas a checagem do linker não protege nada. Sugestão:
  `0x800`.
- **Documentação divergente**: o CONFIGURACAO_HARDWARE.md diz que, em falha, o
  LD2 "pisca rápido sem parar". O código pisca **N vezes e pausa** (N = código
  do erro, §5.1).
- **`FORCE_FEM_SKY66420` sempre ligado**
  (no início de [Src/s2lp_interface.c](Src/s2lp_interface.c)): correto para o
  S2915A1, mas um shield sem FEM (ex.: S2868A1) usado com este firmware seria
  configurado errado.
- **Avisos de compilação** de macros redefinidas em
  [Inc/cube_hal.h:73-81](Inc/cube_hal.h#L73-L81) (`__GPIOx_CLK_ENABLE`,
  `GPIO_SPEED_HIGH`...), que já existem em `stm32_hal_legacy.h`. São
  inofensivos, mas `GPIO_SPEED_HIGH` passa a valer `FREQ_HIGH` em vez de
  `FREQ_VERY_HIGH`. Dá para remover essas linhas do `cube_hal.h`.

### 9.8 [BAIXA] Código morto / legado

- [Src/radio_appli.c](Src/radio_appli.c) (~1.180 linhas) é o exemplo P2P da
  ST. `P2P_Process`, `P2P_Init`, `AppliSendBuff`, as rotinas de baixo consumo
  etc. **nunca são chamadas**. Do arquivo, o firmware usa só `xRadioInit` (lido
  por `S2LPInterfaceInit`), `xCsmaInit` (usado pelo CSMA) e
  `HAL_GPIO_EXTI_Callback`, que altera uma máquina de estados sem uso.
  Remover o resto deixaria o projeto bem mais legível.
- `xRadioInit` (do `radio_appli.c`) e `xAppRadioInit` (do `main.c`) duplicam a
  mesma configuração. Os dois recebem o offset de frequência, mas só o segundo
  é usado.
- [Src/stm32l4xx_it_PATCH.txt](Src/stm32l4xx_it_PATCH.txt) já foi aplicado e pode ser apagado.
- Várias linhas em branco e comentários vazios em `s2lp_interface.c` e
  `radio_appli.c` (restos da remoção dos comentários originais).

---

## 10. O que está bem feito

- ISRs mínimas (só flags) e todo o acesso SPI no laço principal, sem condição
  de corrida no barramento.
- Recuperação do rádio: verificação a cada 250 ms recoloca o S2-LP em RX se ele sair.
- Criptografia correta e conservadora: AEAD padrão (NaCl), verificação em tempo
  constante, autenticação antes de decifrar, cabeçalho autenticado via nonce,
  apagamento de segredos, auto-teste no boot.
- Anti-replay só avança após autenticação; contador de boot persistente com
  duas páginas alternadas e verificação após gravar.
- Falha de segurança no boot impede o uso do rádio (*fail-closed*) e informa o
  motivo pelo LED.
- Verificações de faixa em tempo de compilação (`NODE_ID`, `ECC_NUM_NODES`) e
  limites de tamanho de quadro em `SL_Open`.
