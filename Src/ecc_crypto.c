/**
  * @file    ecc_crypto.c
  * @brief   X25519 + XSalsa20-Poly1305 em C portavel (derivado do TweetNaCl,
  *          dominio publico: https://tweetnacl.cr.yp.to).
  *
  *          Custo aproximado no STM32L476RG a 80 MHz: uma operacao X25519 leva
  *          algumas centenas de ms; ela so e executada na inicializacao (uma
  *          vez por no par). Cifrar/decifrar um quadro leva poucos microssegundos.
  *          Pilha maxima ~1,5 KB, nenhuma alocacao dinamica.
  */
#if defined(__GNUC__) && !defined(__clang__)
/* O build Debug usa -O0; sem otimizacao o X25519 fica ~10x mais lento. */
#pragma GCC optimize ("O2")
#endif

#include "ecc_crypto.h"
#include <string.h>

/* ------------------------------------------------------------------------- */
/* Aritmetica em GF(2^255 - 19): 16 limbs de 16 bits em int64_t.             */
/* ------------------------------------------------------------------------- */
typedef int64_t gf[16];

static const gf GF_121665 = { 0xDB41, 1 };

static void car25519(gf o)
{
  int64_t c;
  for (int i = 0; i < 16; i++)
  {
    o[i] += (int64_t)1 << 16;
    c = o[i] >> 16;
    if (i < 15)
    {
      o[i + 1] += c - 1;
    }
    else
    {
      o[0] += 38 * (c - 1);
    }
    o[i] -= c * 65536;
  }
}

/* Troca p e q se b == 1, em tempo constante. */
static void sel25519(gf p, gf q, int b)
{
  int64_t t, c = ~((int64_t)b - 1);
  for (int i = 0; i < 16; i++)
  {
    t = c & (p[i] ^ q[i]);
    p[i] ^= t;
    q[i] ^= t;
  }
}

static void pack25519(uint8_t *o, const gf n)
{
  int b;
  gf m, t;
  for (int i = 0; i < 16; i++)
  {
    t[i] = n[i];
  }
  car25519(t);
  car25519(t);
  car25519(t);
  for (int j = 0; j < 2; j++)
  {
    m[0] = t[0] - 0xffed;
    for (int i = 1; i < 15; i++)
    {
      m[i] = t[i] - 0xffff - ((m[i - 1] >> 16) & 1);
      m[i - 1] &= 0xffff;
    }
    m[15] = t[15] - 0x7fff - ((m[14] >> 16) & 1);
    b = (int)((m[15] >> 16) & 1);
    m[14] &= 0xffff;
    sel25519(t, m, 1 - b);
  }
  for (int i = 0; i < 16; i++)
  {
    o[2 * i] = (uint8_t)(t[i] & 0xff);
    o[2 * i + 1] = (uint8_t)(t[i] >> 8);
  }
}

static void unpack25519(gf o, const uint8_t *n)
{
  for (int i = 0; i < 16; i++)
  {
    o[i] = n[2 * i] + ((int64_t)n[2 * i + 1] << 8);
  }
  o[15] &= 0x7fff;
}

static void gf_add(gf o, const gf a, const gf b)
{
  for (int i = 0; i < 16; i++)
  {
    o[i] = a[i] + b[i];
  }
}

static void gf_sub(gf o, const gf a, const gf b)
{
  for (int i = 0; i < 16; i++)
  {
    o[i] = a[i] - b[i];
  }
}

static void gf_mul(gf o, const gf a, const gf b)
{
  int64_t t[31];
  for (int i = 0; i < 31; i++)
  {
    t[i] = 0;
  }
  for (int i = 0; i < 16; i++)
  {
    for (int j = 0; j < 16; j++)
    {
      t[i + j] += a[i] * b[j];
    }
  }
  for (int i = 0; i < 15; i++)
  {
    t[i] += 38 * t[i + 16];
  }
  for (int i = 0; i < 16; i++)
  {
    o[i] = t[i];
  }
  car25519(o);
  car25519(o);
}

static void gf_sqr(gf o, const gf a)
{
  gf_mul(o, a, a);
}

/* o = i^(p-2) = 1/i */
static void inv25519(gf o, const gf i)
{
  gf c;
  for (int a = 0; a < 16; a++)
  {
    c[a] = i[a];
  }
  for (int a = 253; a >= 0; a--)
  {
    gf_sqr(c, c);
    if (a != 2 && a != 4)
    {
      gf_mul(c, c, i);
    }
  }
  for (int a = 0; a < 16; a++)
  {
    o[a] = c[a];
  }
}

int ecc_x25519(uint8_t out[ECC_KEY_LEN], const uint8_t scalar[ECC_KEY_LEN],
               const uint8_t point[ECC_KEY_LEN])
{
  uint8_t z[32];
  gf x, a, b, c, d, e, f;
  uint8_t acc = 0;

  memcpy(z, scalar, 32);
  z[31] = (uint8_t)((z[31] & 127) | 64);
  z[0] &= 248;

  unpack25519(x, point);
  for (int i = 0; i < 16; i++)
  {
    b[i] = x[i];
    d[i] = a[i] = c[i] = 0;
  }
  a[0] = d[0] = 1;

  /* Escada de Montgomery */
  for (int i = 254; i >= 0; --i)
  {
    int r = (z[i >> 3] >> (i & 7)) & 1;
    sel25519(a, b, r);
    sel25519(c, d, r);
    gf_add(e, a, c);
    gf_sub(a, a, c);
    gf_add(c, b, d);
    gf_sub(b, b, d);
    gf_sqr(d, e);
    gf_sqr(f, a);
    gf_mul(a, c, a);
    gf_mul(c, b, e);
    gf_add(e, a, c);
    gf_sub(a, a, c);
    gf_sqr(b, a);
    gf_sub(c, d, f);
    gf_mul(a, c, GF_121665);
    gf_add(a, a, d);
    gf_mul(c, c, a);   /* z2 = E * (AA + a24 * E) */
    gf_mul(a, d, f);
    gf_mul(d, b, x);
    gf_sqr(b, e);
    sel25519(a, b, r);
    sel25519(c, d, r);
  }
  inv25519(c, c);
  gf_mul(a, a, c);
  pack25519(out, a);

  ecc_wipe(z, sizeof(z));
  ecc_wipe(a, sizeof(gf));
  ecc_wipe(b, sizeof(gf));
  ecc_wipe(c, sizeof(gf));
  ecc_wipe(d, sizeof(gf));
  ecc_wipe(e, sizeof(gf));
  ecc_wipe(f, sizeof(gf));

  for (int i = 0; i < 32; i++)
  {
    acc |= out[i];
  }
  return (acc == 0) ? -1 : 0;
}

void ecc_x25519_base(uint8_t pub[ECC_KEY_LEN], const uint8_t priv[ECC_KEY_LEN])
{
  static const uint8_t base[32] = { 9 };
  (void)ecc_x25519(pub, priv, base);
}

/* ------------------------------------------------------------------------- */
/* Salsa20 / HSalsa20 / XSalsa20                                             */
/* ------------------------------------------------------------------------- */
static const uint8_t SIGMA[16] = { 'e', 'x', 'p', 'a', 'n', 'd', ' ', '3',
                                   '2', '-', 'b', 'y', 't', 'e', ' ', 'k' };

static uint32_t ld32(const uint8_t *x)
{
  return (uint32_t)x[0] | ((uint32_t)x[1] << 8) | ((uint32_t)x[2] << 16) | ((uint32_t)x[3] << 24);
}

static void st32(uint8_t *x, uint32_t u)
{
  x[0] = (uint8_t)u;
  x[1] = (uint8_t)(u >> 8);
  x[2] = (uint8_t)(u >> 16);
  x[3] = (uint8_t)(u >> 24);
}

#define ROTL32(v, n) (((v) << (n)) | ((v) >> (32 - (n))))
#define QR(a, b, c, d)                \
  do {                                \
    x[b] ^= ROTL32(x[a] + x[d], 7);   \
    x[c] ^= ROTL32(x[b] + x[a], 9);   \
    x[d] ^= ROTL32(x[c] + x[b], 13);  \
    x[a] ^= ROTL32(x[d] + x[c], 18);  \
  } while (0)

/* hsalsa = 0: bloco Salsa20 de 64 bytes; hsalsa = 1: subchave HSalsa20 de 32 bytes. */
static void salsa20_core(uint8_t *out, const uint8_t in[16], const uint8_t k[32], int hsalsa)
{
  uint32_t x[16], y[16];

  for (int i = 0; i < 4; i++)
  {
    x[5 * i] = ld32(SIGMA + 4 * i);
    x[1 + i] = ld32(k + 4 * i);
    x[6 + i] = ld32(in + 4 * i);
    x[11 + i] = ld32(k + 16 + 4 * i);
  }
  memcpy(y, x, sizeof(x));

  for (int i = 0; i < 10; i++)
  {
    QR(0, 4, 8, 12);
    QR(5, 9, 13, 1);
    QR(10, 14, 2, 6);
    QR(15, 3, 7, 11);
    QR(0, 1, 2, 3);
    QR(5, 6, 7, 4);
    QR(10, 11, 8, 9);
    QR(15, 12, 13, 14);
  }

  if (hsalsa)
  {
    for (int i = 0; i < 4; i++)
    {
      st32(out + 4 * i, x[5 * i]);
      st32(out + 16 + 4 * i, x[6 + i]);
    }
  }
  else
  {
    for (int i = 0; i < 16; i++)
    {
      st32(out + 4 * i, x[i] + y[i]);
    }
  }
  ecc_wipe(x, sizeof(x));
  ecc_wipe(y, sizeof(y));
}

/* Fluxo XSalsa20: os 32 primeiros bytes viram a chave Poly1305 e o restante
 * cifra os dados (mesmo layout de crypto_secretbox). */
static void xsalsa20_xor(uint8_t *out, const uint8_t *in, size_t len,
                         uint8_t polykey[32], const uint8_t nonce[ECC_NONCE_LEN],
                         const uint8_t key[ECC_KEY_LEN])
{
  uint8_t subkey[32], blk_in[16], ks[64];
  uint64_t ctr = 0;
  size_t off = 0, total = len + 32;

  salsa20_core(subkey, nonce, key, 1);
  memcpy(blk_in, nonce + 16, 8);

  while (off < total)
  {
    for (int i = 0; i < 8; i++)
    {
      blk_in[8 + i] = (uint8_t)(ctr >> (8 * i));
    }
    salsa20_core(ks, blk_in, subkey, 0);
    for (size_t i = 0; i < 64 && off < total; i++, off++)
    {
      if (off < 32)
      {
        polykey[off] = ks[i];
      }
      else
      {
        out[off - 32] = in[off - 32] ^ ks[i];
      }
    }
    ctr++;
  }
  ecc_wipe(subkey, sizeof(subkey));
  ecc_wipe(ks, sizeof(ks));
}

/* ------------------------------------------------------------------------- */
/* Poly1305 (17 limbs de 8 bits)                                             */
/* ------------------------------------------------------------------------- */
static void add1305(uint32_t *h, const uint32_t *c)
{
  uint32_t u = 0;
  for (int j = 0; j < 17; j++)
  {
    u += h[j] + c[j];
    h[j] = u & 255;
    u >>= 8;
  }
}

static void poly1305(uint8_t out[16], const uint8_t *m, size_t n, const uint8_t k[32])
{
  static const uint32_t minusp[17] = { 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 252 };
  uint32_t s, u, x[17], r[17], h[17], c[17], g[17];
  size_t j;

  for (j = 0; j < 17; j++)
  {
    r[j] = h[j] = 0;
  }
  for (j = 0; j < 16; j++)
  {
    r[j] = k[j];
  }
  r[3] &= 15;
  r[4] &= 252;
  r[7] &= 15;
  r[8] &= 252;
  r[11] &= 15;
  r[12] &= 252;
  r[15] &= 15;

  while (n > 0)
  {
    for (j = 0; j < 17; j++)
    {
      c[j] = 0;
    }
    for (j = 0; (j < 16) && (j < n); ++j)
    {
      c[j] = m[j];
    }
    c[j] = 1;
    m += j;
    n -= j;
    add1305(h, c);
    for (int i = 0; i < 17; i++)
    {
      x[i] = 0;
      for (int jj = 0; jj < 17; jj++)
      {
        x[i] += h[jj] * ((jj <= i) ? r[i - jj] : 320 * r[i + 17 - jj]);
      }
    }
    for (int i = 0; i < 17; i++)
    {
      h[i] = x[i];
    }
    u = 0;
    for (j = 0; j < 16; j++)
    {
      u += h[j];
      h[j] = u & 255;
      u >>= 8;
    }
    u += h[16];
    h[16] = u & 3;
    u = 5 * (u >> 2);
    for (j = 0; j < 16; j++)
    {
      u += h[j];
      h[j] = u & 255;
      u >>= 8;
    }
    u += h[16];
    h[16] = u;
  }

  for (j = 0; j < 17; j++)
  {
    g[j] = h[j];
  }
  add1305(h, minusp);
  s = (uint32_t)(-(int32_t)(h[16] >> 7));
  for (j = 0; j < 17; j++)
  {
    h[j] ^= s & (g[j] ^ h[j]);
  }
  for (j = 0; j < 16; j++)
  {
    c[j] = k[j + 16];
  }
  c[16] = 0;
  add1305(h, c);
  for (j = 0; j < 16; j++)
  {
    out[j] = (uint8_t)h[j];
  }
  ecc_wipe(r, sizeof(r));
  ecc_wipe(h, sizeof(h));
}

/* ------------------------------------------------------------------------- */
/* API                                                                       */
/* ------------------------------------------------------------------------- */
void ecc_wipe(void *p, size_t len)
{
  volatile uint8_t *v = (volatile uint8_t *)p;
  while (len--)
  {
    *v++ = 0;
  }
}

int ecc_verify(const uint8_t *a, const uint8_t *b, size_t len)
{
  uint8_t d = 0;
  for (size_t i = 0; i < len; i++)
  {
    d |= a[i] ^ b[i];
  }
  return (d == 0) ? 0 : -1;
}

int ecc_shared_key(uint8_t key[ECC_KEY_LEN], const uint8_t my_priv[ECC_KEY_LEN],
                   const uint8_t peer_pub[ECC_KEY_LEN])
{
  static const uint8_t zero[16] = { 0 };
  uint8_t s[32];
  int ret = ecc_x25519(s, my_priv, peer_pub);
  salsa20_core(key, zero, s, 1);
  ecc_wipe(s, sizeof(s));
  return ret;
}

void ecc_seal(uint8_t *out, uint8_t tag[ECC_TAG_LEN], const uint8_t *in, size_t len,
              const uint8_t nonce[ECC_NONCE_LEN], const uint8_t key[ECC_KEY_LEN])
{
  uint8_t polykey[32];
  xsalsa20_xor(out, in, len, polykey, nonce, key);
  poly1305(tag, out, len, polykey);
  ecc_wipe(polykey, sizeof(polykey));
}

int ecc_open(uint8_t *out, const uint8_t *in, size_t len, const uint8_t tag[ECC_TAG_LEN],
             const uint8_t nonce[ECC_NONCE_LEN], const uint8_t key[ECC_KEY_LEN])
{
  uint8_t polykey[32], calc[ECC_TAG_LEN];
  int ret;

  xsalsa20_xor(NULL, NULL, 0, polykey, nonce, key);
  poly1305(calc, in, len, polykey);
  ret = ecc_verify(calc, tag, ECC_TAG_LEN);
  if (ret == 0)
  {
    xsalsa20_xor(out, in, len, polykey, nonce, key);
  }
  ecc_wipe(polykey, sizeof(polykey));
  return ret;
}

int ecc_self_test(void)
{
  /* RFC 7748 secao 6.1 */
  static const uint8_t alice_sk[32] = {
    0x77, 0x07, 0x6d, 0x0a, 0x73, 0x18, 0xa5, 0x7d, 0x3c, 0x16, 0xc1, 0x72, 0x51, 0xb2, 0x66, 0x45,
    0xdf, 0x4c, 0x2f, 0x87, 0xeb, 0xc0, 0x99, 0x2a, 0xb1, 0x77, 0xfb, 0xa5, 0x1d, 0xb9, 0x2c, 0x2a };
  static const uint8_t bob_pk[32] = {
    0xde, 0x9e, 0xdb, 0x7d, 0x7b, 0x7d, 0xc1, 0xb4, 0xd3, 0x5b, 0x61, 0xc2, 0xec, 0xe4, 0x35, 0x37,
    0x3f, 0x83, 0x43, 0xc8, 0x5b, 0x78, 0x67, 0x4d, 0xad, 0xfc, 0x7e, 0x14, 0x6f, 0x88, 0x2b, 0x4f };
  /* HSalsa20(X25519(alice_sk, bob_pk), 0) - "firstkey" dos testes do NaCl */
  static const uint8_t box_key[32] = {
    0x1b, 0x27, 0x55, 0x64, 0x73, 0xe9, 0x85, 0xd4, 0x62, 0xcd, 0x51, 0x19, 0x7a, 0x9a, 0x46, 0xc7,
    0x60, 0x09, 0x54, 0x9e, 0xac, 0x64, 0x74, 0xf2, 0x06, 0xc4, 0xee, 0x08, 0x44, 0xf6, 0x83, 0x89 };
  /* RFC 8439 secao 2.5.2 */
  static const uint8_t poly_key[32] = {
    0x85, 0xd6, 0xbe, 0x78, 0x57, 0x55, 0x6d, 0x33, 0x7f, 0x44, 0x52, 0xfe, 0x42, 0xd5, 0x06, 0xa8,
    0x01, 0x03, 0x80, 0x8a, 0xfb, 0x0d, 0xb2, 0xfd, 0x4a, 0xbf, 0xf6, 0xaf, 0x41, 0x49, 0xf5, 0x1b };
  static const uint8_t poly_tag[16] = {
    0xa8, 0x06, 0x1d, 0xc1, 0x30, 0x51, 0x36, 0xc6, 0xc2, 0x2b, 0x8b, 0xaf, 0x0c, 0x01, 0x27, 0xa9 };
  static const char poly_msg[] = "Cryptographic Forum Research Group";

  uint8_t key[32], tag[16], nonce[ECC_NONCE_LEN] = { 1, 2, 3 };
  uint8_t msg[40], buf[40];

  if (ecc_shared_key(key, alice_sk, bob_pk) != 0 || ecc_verify(key, box_key, 32) != 0)
  {
    return -1;
  }

  poly1305(tag, (const uint8_t *)poly_msg, sizeof(poly_msg) - 1, poly_key);
  if (ecc_verify(tag, poly_tag, 16) != 0)
  {
    return -2;
  }

  /* Ida e volta atravessando dois blocos Salsa20 e deteccao de adulteracao. */
  for (size_t i = 0; i < sizeof(msg); i++)
  {
    msg[i] = (uint8_t)(i * 7 + 1);
  }
  ecc_seal(buf, tag, msg, sizeof(msg), nonce, key);
  if (ecc_verify(buf, msg, sizeof(msg)) == 0)
  {
    return -3;
  }
  if (ecc_open(buf, buf, sizeof(buf), tag, nonce, key) != 0 || ecc_verify(buf, msg, sizeof(msg)) != 0)
  {
    return -4;
  }
  ecc_seal(buf, tag, msg, sizeof(msg), nonce, key);
  buf[sizeof(buf) - 1] ^= 0x01;
  if (ecc_open(buf, buf, sizeof(buf), tag, nonce, key) == 0)
  {
    return -5;
  }

  ecc_wipe(key, sizeof(key));
  return 0;
}
