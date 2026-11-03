# NUCLEO-L476RG + X-NUCLEO-S2915A1

O firmware configura o SPI1 pelo driver do shield em modo master full-duplex,
8 bits, MSB first, clock idle low, captura na primeira borda e NSS por software.
O clock SPI usa PB3; MISO/MOSI usam PA6/PA7.

| Pino/periferico | Funcao |
| --- | --- |
| PA1 | GPIO de saida — CS do S2-LP |
| PA8 | GPIO de saida — SDN do S2-LP |
| PC0 | EXTI0 na borda de descida — IRQ/GPIO3 do S2-LP |
| PC13 | EXTI13 na borda de descida — botao USER/B1 |
| PA5 | GPIO de saida — LED2/LD2 |
| PA0 | GPIO de saida — CSD do FEM SKY66420 |
| PA4 | GPIO de saida — CPS do FEM SKY66420 |
| PB0 | GPIO de saida — CTX do FEM SKY66420 |
| NVIC | EXTI0_IRQn e EXTI15_10_IRQn habilitadas pelo BSP/driver |

O FEM e chaveado automaticamente: `S2LPCmdStrobeTx()` coloca o SKY66420 em TX
(PA ligado) e `S2LPCmdStrobeRx()` em RX (LNA ligado).

O projeto nao continha um arquivo `.ioc`; as configuracoes acima sao aplicadas
pelos drivers/firmware. Se um `.ioc` for criado no CubeMX, selecionar a placa
NUCLEO-L476RG e replicar estes pinos e o modo SPI antes de regenerar o projeto.

O botao B1 transmite o comando `0xAA` em 915-928 MHz, cifrado com ECC (ver
abaixo), com salto de frequencia em 50 canais. O recebimento de um comando
autentico alterna o LD2.

## Radio: alcance maximo e salto de frequencia

Parametros em `Inc/aquaalert_rf.h`; detalhes e racional em `DOCUMENTACAO.md`.

- **Potencia:** o S2-LP entrega +12 dBm ao FEM SKY66420 (ganho 16 dB), o que
  da ~+27 dBm na antena. Limite absoluto na entrada do FEM: +17 dBm.
- **Sensibilidade:** 2-GFSK 4,8 kbps, desvio 4,8 kHz, filtro de RX 60 kHz,
  FEC ligado, preambulo 8 bytes, CRC 16 bits, LNA do FEM em RX.
- **Salto de frequencia:** 50 canais de ~250 kHz entre 915,375 e ~927,56 MHz.
  Cada alerta e enviado uma vez em cada canal (ordem pseudoaleatoria, ~8 s por
  destino). O receptor escuta um canal sorteado e troca a cada 10 min.
- **Ocupacao:** no maximo 0,4 s por canal a cada 20 s. Se o botao for apertado
  de novo antes disso, o alerta fica pendente e sai assim que a janela liberar.
- Antena com ganho acima de 6 dBi: reduzir `AA_FEM_DRIVE_DBM` na mesma medida.

## Comunicacao cifrada (ECC)

Cada placa e um no com ID (1..N) e um par de chaves X25519 (Curve25519).
Somente nos cujas chaves publicas estao em `Inc/ecc_keys.h` conseguem ler ou
gerar mensagens aceitas.

- **Acordo de chaves:** na inicializacao, cada no calcula por ECDH (X25519) uma
  chave exclusiva com cada outro no permitido (`Src/secure_link.c`).
- **Cifra autenticada:** cada quadro e cifrado e autenticado com
  XSalsa20-Poly1305 (`Src/ecc_crypto.c`). Quadros de nos desconhecidos,
  adulterados ou destinados a outro no sao descartados.
- **Anti-replay:** cada quadro leva um contador (contador de boot gravado em
  flash + contador de mensagens). Quadros repetidos ou antigos sao recusados.
- **Formato do quadro (29 bytes para o comando de 1 byte):**
  `EC 01 origem destino contador[8] | dado cifrado | etiqueta[16]`.
  Com N nos, o botao envia um quadro para cada um dos outros N-1 nos.

### Gravar as placas

0. `Inc/ecc_keys.h` **nao esta no repositorio** (esta no `.gitignore`). Gere-o
   (ver abaixo) ou receba-o por um canal seguro de quem gravou as outras
   placas. Todas as placas precisam do **mesmo** arquivo.
1. Escolher o `NODE_ID` de cada placa:
   - PlatformIO: `pio run -e node1 -t upload` (placa 1), `-e node2` (placa 2);
   - CubeIDE: ajustar `#define NODE_ID` em `Inc/ecc_keys.h`, ou definir
     `NODE_ID=n` em *Properties > C/C++ Build > Settings > MCU GCC Compiler >
     Preprocessor*.
2. Compilar e gravar. Repetir para cada placa com o seu `NODE_ID`.

Ao ligar, o LD2 fica aceso enquanto o auto-teste criptografico roda e as
chaves sao derivadas (alguns segundos). Se houver falha no auto-teste, nas
chaves ou na flash, o radio nao e usado e o LD2 pisca N vezes, pausa e repete:
N = 1 (auto-teste), 2 (chave invalida), 3 (flash).

### Gerar novas chaves (adicionar ou revogar nos)

No PC, a partir da pasta `AquaAlert`. Com Python 3 (sem dependencias):

```
python Tools/gerar_chaves_ecc.py 2 Inc/ecc_keys.h
```

Ou com um compilador C (ex. MinGW/gcc):

```
gcc -O2 -IInc Tools/gerar_chaves_ecc.c Src/ecc_crypto.c -o gerar_chaves_ecc
gerar_chaves_ecc 2 Inc/ecc_keys.h
```

Depois regravar **todas** as placas. Para revogar um no, gere chaves sem ele.
Ao mudar o numero de nos, ajuste tambem as envs `node*` do `platformio.ini`.

**Importante:** as chaves geradas antes de 2026-11-03 foram publicadas no
GitHub e estao comprometidas; o arquivo atual foi regenerado. Placas gravadas
com as chaves antigas nao conversam com as novas.

### Observacoes

- As 2 ultimas paginas da flash (0x080FF000-0x080FFFFF, banco 2) ficam
  reservadas ao contador de boot; o linker script foi reduzido para 1020 KB.
- `Inc/ecc_keys.h` contem as chaves privadas: nao versionar nem compartilhar
  (o modelo sem segredos e `Inc/ecc_keys.example.h`). Em producao, ativar a protecao de leitura (RDP nivel 1) para impedir a
  extracao da chave via SWD.
- Se uma placa receptora reiniciar, ela volta a aceitar o proximo quadro valido
  de cada par; um quadro antigo capturado poderia ser aceito uma unica vez
  nesse momento.
