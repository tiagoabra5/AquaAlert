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
| NVIC | EXTI0_IRQn e EXTI15_10_IRQn habilitadas pelo BSP/driver |

O projeto nao continha um arquivo `.ioc`; as configuracoes acima sao aplicadas
pelos drivers/firmware. Se um `.ioc` for criado no CubeMX, selecionar a placa
NUCLEO-L476RG e replicar estes pinos e o modo SPI antes de regenerar o projeto.

O botao B1 transmite o comando `0xAA` em 915 MHz, cifrado com ECC (ver abaixo).
O recebimento de um comando autentico alterna o LD2.

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

1. Em `Inc/ecc_keys.h`, ajustar `#define NODE_ID` (1 na primeira placa, 2 na
   segunda...), ou definir `NODE_ID=n` em *Properties > C/C++ Build >
   Settings > MCU GCC Compiler > Preprocessor*.
2. Compilar e gravar. Repetir para cada placa com o seu `NODE_ID`.

Ao ligar, o LD2 fica aceso enquanto o auto-teste criptografico roda e as
chaves sao derivadas (alguns segundos). Se o LD2 piscar rapido sem parar,
houve falha no auto-teste, nas chaves ou na flash, e o radio nao e usado.

### Gerar novas chaves (adicionar ou revogar nos)

No PC, a partir da pasta `AquaAlert` (qualquer compilador C, ex. MinGW/gcc):

```
gcc -O2 -IInc Tools/gerar_chaves_ecc.c Src/ecc_crypto.c -o gerar_chaves_ecc
gerar_chaves_ecc 3 Inc/ecc_keys.h
```

Depois regravar **todas** as placas. Para revogar um no, gere chaves sem ele.

### Observacoes

- As 2 ultimas paginas da flash (0x080FF000-0x080FFFFF, banco 2) ficam
  reservadas ao contador de boot; o linker script foi reduzido para 1020 KB.
- `Inc/ecc_keys.h` contem as chaves privadas: nao versionar nem compartilhar.
  Em producao, ativar a protecao de leitura (RDP nivel 1) para impedir a
  extracao da chave via SWD.
- Se uma placa receptora reiniciar, ela volta a aceitar o proximo quadro valido
  de cada par; um quadro antigo capturado poderia ser aceito uma unica vez
  nesse momento.
