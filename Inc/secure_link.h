/**
  * @file    secure_link.h
  * @brief   Enlace de radio cifrado entre nos AquaAlert permitidos.
  *
  *          Cada no possui um par de chaves X25519 (Inc/ecc_keys.h). Na
  *          inicializacao, o no deriva por ECDH uma chave simetrica com cada no
  *          da lista de permitidos. Cada quadro e cifrado e autenticado com
  *          XSalsa20-Poly1305 usando a chave do par origem/destino, de modo que
  *          somente o destinatario permitido consegue ler o conteudo e somente
  *          um no permitido consegue produzir um quadro aceito.
  *
  *          Quadro (SL_HEADER_LEN + n + ECC_TAG_LEN bytes):
  *            [0] SL_MAGIC  [1] SL_VERSION  [2] origem  [3] destino
  *            [4..11] contador (LE: 32 bits de boot | 32 bits de mensagem)
  *            [12..]  dados cifrados  |  etiqueta Poly1305 (16 bytes)
  *          O cabecalho inteiro compoe o nonce, portanto qualquer alteracao
  *          nele invalida a etiqueta.
  */
#ifndef SECURE_LINK_H
#define SECURE_LINK_H

#include <stdint.h>
#include "ecc_crypto.h"

#define SL_MAGIC          0xECU
#define SL_VERSION        0x01U
#define SL_HEADER_LEN     12U
#define SL_PLAINTEXT_MAX  32U
#define SL_FRAME_LEN(n)   (SL_HEADER_LEN + (n) + ECC_TAG_LEN)
#define SL_FRAME_MAX      SL_FRAME_LEN(SL_PLAINTEXT_MAX)

typedef enum
{
  SL_OK = 0,
  SL_ERR_SELFTEST,      /* auto-teste criptografico falhou */
  SL_ERR_KEY,           /* chave invalida na tabela ecc_keys.h */
  SL_ERR_FLASH,         /* falha ao gravar o contador de boot */
  SL_ERR_PARAM,
  SL_ERR_FORMAT,        /* quadro malformado ou de outra rede */
  SL_ERR_NOT_FOR_ME,    /* destino e outro no */
  SL_ERR_UNKNOWN_PEER,  /* origem nao esta na lista de permitidos */
  SL_ERR_AUTH,          /* etiqueta invalida: adulterado ou chave errada */
  SL_ERR_REPLAY,        /* quadro repetido/antigo */
  SL_ERR_COUNTER        /* contador de mensagens esgotado (reinicie o no) */
} SL_Status;

/* Executa o auto-teste, avanca o contador de boot e deriva as chaves dos pares.
 * Leva alguns segundos no L476 (uma operacao X25519 por no permitido). */
SL_Status SL_Init(void);

uint8_t SL_GetNodeId(void);

/* Quantidade de nos permitidos; os IDs vao de 1 a SL_GetNodeCount(). */
uint8_t SL_GetNodeCount(void);

/* Monta um quadro cifrado para o no dst (diferente do proprio).
 * frame deve ter ao menos SL_FRAME_LEN(ptLen) bytes. */
SL_Status SL_Seal(uint8_t dst, const uint8_t *pt, uint8_t ptLen,
                  uint8_t *frame, uint8_t *frameLen);

/* Valida e decifra um quadro recebido. pt deve ter SL_PLAINTEXT_MAX bytes. */
SL_Status SL_Open(const uint8_t *frame, uint8_t frameLen,
                  uint8_t *src, uint8_t *pt, uint8_t *ptLen);

#endif /* SECURE_LINK_H */
