/**
  * @file    gerar_chaves_ecc.c
  * @brief   Gera os pares de chaves X25519 dos nos AquaAlert e escreve
  *          Inc/ecc_keys.h. Roda no PC (nao no microcontrolador).
  *
  *  Compilar e executar a partir da pasta AquaAlert (qualquer compilador C99):
  *    gcc -O2 -IInc Tools/gerar_chaves_ecc.c Src/ecc_crypto.c -o gerar_chaves_ecc
  *    ./gerar_chaves_ecc 2 Inc/ecc_keys.h
  *
  *  Argumentos: [numero de nos (2..254), padrao 2] [arquivo de saida].
  *  Para revogar um no, gere chaves novas sem ele e regrave todas as placas.
  */
#if defined(_WIN32)
#define _CRT_RAND_S
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "ecc_crypto.h"

static int random_bytes(uint8_t *buf, size_t len)
{
#if defined(_WIN32)
  for (size_t i = 0; i < len; i++)
  {
    unsigned int v;
    if (rand_s(&v) != 0)
    {
      return -1;
    }
    buf[i] = (uint8_t)v;
  }
  return 0;
#else
  FILE *f = fopen("/dev/urandom", "rb");
  size_t n;
  if (f == NULL)
  {
    return -1;
  }
  n = fread(buf, 1, len, f);
  fclose(f);
  return (n == len) ? 0 : -1;
#endif
}

static void print_key(FILE *out, const uint8_t k[ECC_KEY_LEN])
{
  fprintf(out, "{ ");
  for (int i = 0; i < 32; i++)
  {
    fprintf(out, "0x%02x%s", k[i], (i == 31) ? " }" : (i == 15) ? ",\n      " : ", ");
  }
}

int main(int argc, char **argv)
{
  int nodes = (argc > 1) ? atoi(argv[1]) : 2;
  const char *path = (argc > 2) ? argv[2] : "Inc/ecc_keys.h";
  static uint8_t priv[254][ECC_KEY_LEN];
  static uint8_t pub[254][ECC_KEY_LEN];
  FILE *out;

  if (nodes < 2 || nodes > 254)
  {
    fprintf(stderr, "Numero de nos deve estar entre 2 e 254.\n");
    return 1;
  }
  if (ecc_self_test() != 0)
  {
    fprintf(stderr, "Auto-teste criptografico falhou.\n");
    return 1;
  }

  for (int n = 0; n < nodes; n++)
  {
    if (random_bytes(priv[n], ECC_KEY_LEN) != 0)
    {
      fprintf(stderr, "Falha ao obter bytes aleatorios do sistema.\n");
      return 1;
    }
    priv[n][0] &= 248;
    priv[n][31] = (uint8_t)((priv[n][31] & 127) | 64);
    ecc_x25519_base(pub[n], priv[n]);
  }

  out = fopen(path, "w");
  if (out == NULL)
  {
    fprintf(stderr, "Nao foi possivel criar %s\n", path);
    return 1;
  }

  fprintf(out, "/* Gerado por Tools/gerar_chaves_ecc.c. Contem chaves privadas: NAO versionar/compartilhar. */\n");
  fprintf(out, "#ifndef ECC_KEYS_H\n#define ECC_KEYS_H\n\n#include <stdint.h>\n\n");
  fprintf(out, "/* ID deste no (1..%d). Altere aqui ou defina -DNODE_ID=n nas opcoes do compilador. */\n", nodes);
  fprintf(out, "#ifndef NODE_ID\n#define NODE_ID 1\n#endif\n\n");
  fprintf(out, "#define ECC_NUM_NODES %d\n\n", nodes);
  for (int n = 0; n < nodes; n++)
  {
    fprintf(out, "%s NODE_ID == %d\n", (n == 0) ? "#if" : "#elif", n + 1);
    fprintf(out, "static const uint8_t ECC_NODE_PRIVATE_KEY[32] =\n      ");
    print_key(out, priv[n]);
    fprintf(out, ";\n");
  }
  fprintf(out, "#else\n#error \"NODE_ID invalido\"\n#endif\n\n");
  fprintf(out, "/* Chaves publicas dos nos permitidos; indice = NODE_ID - 1. */\n");
  fprintf(out, "static const uint8_t ECC_NODE_PUBLIC_KEYS[ECC_NUM_NODES][32] = {\n");
  for (int n = 0; n < nodes; n++)
  {
    fprintf(out, "  /* no %d */ ", n + 1);
    print_key(out, pub[n]);
    fprintf(out, "%s\n", (n < nodes - 1) ? "," : "");
  }
  fprintf(out, "};\n\n#endif\n");
  fclose(out);

  ecc_wipe(priv, sizeof(priv));
  printf("Chaves de %d nos gravadas em %s\n", nodes, path);
  return 0;
}
