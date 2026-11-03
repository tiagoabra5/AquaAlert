/* MODELO de Inc/ecc_keys.h -- NAO contem chaves reais e nao e compilado.
 *
 * O arquivo real Inc/ecc_keys.h contem as chaves privadas dos nos, esta no
 * .gitignore e nunca deve ser versionado. Para cria-lo, na pasta AquaAlert:
 *
 *     python Tools/gerar_chaves_ecc.py 2 Inc/ecc_keys.h
 *
 * (ou compile Tools/gerar_chaves_ecc.c, ver CONFIGURACAO_HARDWARE.md).
 * Todas as placas da rede precisam ser gravadas com o MESMO ecc_keys.h,
 * cada uma com o seu NODE_ID. Distribua o arquivo por um canal seguro.
 */
#ifndef ECC_KEYS_H
#define ECC_KEYS_H

#include <stdint.h>

#ifndef NODE_ID
#define NODE_ID 1
#endif

#define ECC_NUM_NODES 2

#if NODE_ID == 1
static const uint8_t ECC_NODE_PRIVATE_KEY[32] = { 0 /* gerado */ };
#elif NODE_ID == 2
static const uint8_t ECC_NODE_PRIVATE_KEY[32] = { 0 /* gerado */ };
#else
#error "NODE_ID invalido"
#endif

static const uint8_t ECC_NODE_PUBLIC_KEYS[ECC_NUM_NODES][32] = {
  /* no 1 */ { 0 /* gerado */ },
  /* no 2 */ { 0 /* gerado */ }
};

#endif
