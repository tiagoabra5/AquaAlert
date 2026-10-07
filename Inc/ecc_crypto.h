/**
  * @file    ecc_crypto.h
  * @brief   Criptografia de curva eliptica para o enlace de radio AquaAlert.
  *
  *          - X25519 (ECDH sobre Curve25519, RFC 7748) para acordo de chaves;
  *          - XSalsa20-Poly1305 (construcao "crypto_box" do NaCl) para cifrar e
  *            autenticar cada mensagem com a chave derivada do ECDH.
  *
  *          Implementacao em C portavel, sem alocacao dinamica e em tempo
  *          constante, baseada no TweetNaCl (dominio publico). Pensada para o
  *          STM32L476RG, que nao possui acelerador criptografico em hardware.
  */
#ifndef ECC_CRYPTO_H
#define ECC_CRYPTO_H

#include <stddef.h>
#include <stdint.h>

#define ECC_KEY_LEN    32U
#define ECC_NONCE_LEN  24U
#define ECC_TAG_LEN    16U

/* out = scalar * point. Retorna 0, ou -1 se o resultado for o ponto neutro
 * (chave publica invalida/de ordem baixa). */
int ecc_x25519(uint8_t out[ECC_KEY_LEN], const uint8_t scalar[ECC_KEY_LEN],
               const uint8_t point[ECC_KEY_LEN]);

/* Chave publica correspondente a uma chave privada. */
void ecc_x25519_base(uint8_t pub[ECC_KEY_LEN], const uint8_t priv[ECC_KEY_LEN]);

/* Chave simetrica do par (ECDH + HSalsa20, igual a crypto_box_beforenm).
 * O resultado e o mesmo nos dois lados. Retorna 0 ou -1. */
int ecc_shared_key(uint8_t key[ECC_KEY_LEN], const uint8_t my_priv[ECC_KEY_LEN],
                   const uint8_t peer_pub[ECC_KEY_LEN]);

/* Cifra e autentica len bytes. out pode ser igual a in.
 * O nonce NUNCA pode se repetir para a mesma chave. */
void ecc_seal(uint8_t *out, uint8_t tag[ECC_TAG_LEN], const uint8_t *in, size_t len,
              const uint8_t nonce[ECC_NONCE_LEN], const uint8_t key[ECC_KEY_LEN]);

/* Verifica a etiqueta e decifra. Retorna 0 se autentica; -1 caso contrario
 * (nesse caso out nao e escrito). out pode ser igual a in. */
int ecc_open(uint8_t *out, const uint8_t *in, size_t len, const uint8_t tag[ECC_TAG_LEN],
             const uint8_t nonce[ECC_NONCE_LEN], const uint8_t key[ECC_KEY_LEN]);

/* Compara em tempo constante. Retorna 0 se iguais. */
int ecc_verify(const uint8_t *a, const uint8_t *b, size_t len);

/* Apaga memoria sensivel (nao removido pelo otimizador). */
void ecc_wipe(void *p, size_t len);

/* Auto-teste com vetores do RFC 7748 / NaCl / RFC 8439. Retorna 0 se OK. */
int ecc_self_test(void);

#endif /* ECC_CRYPTO_H */
