#!/usr/bin/env python3
"""Gera os pares de chaves X25519 dos nos AquaAlert e escreve Inc/ecc_keys.h.

Equivalente a Tools/gerar_chaves_ecc.c, para quem nao tem compilador C no PC.
Usa so a biblioteca padrao (secrets = gerador criptografico do sistema).

Uso (a partir da pasta AquaAlert):
    python Tools/gerar_chaves_ecc.py [numero_de_nos (2..254), padrao 2] [arquivo]

O arquivo gerado contem chaves privadas: ele esta no .gitignore e NAO deve ser
versionado nem compartilhado. Depois de gerar, regrave TODAS as placas.
"""
import datetime
import secrets
import sys

P = 2**255 - 19
A24 = 121665


def _clamp(k: bytes) -> int:
    b = bytearray(k)
    b[0] &= 248
    b[31] = (b[31] & 127) | 64
    return int.from_bytes(b, "little")


def x25519(scalar: bytes, point: bytes) -> bytes:
    """X25519 (RFC 7748), escada de Montgomery."""
    k = _clamp(scalar)
    x1 = int.from_bytes(point, "little") & ((1 << 255) - 1)
    x2, z2, x3, z3, swap = 1, 0, x1, 1, 0
    for t in reversed(range(255)):
        bit = (k >> t) & 1
        swap ^= bit
        if swap:
            x2, x3, z2, z3 = x3, x2, z3, z2
        swap = bit
        a, b = (x2 + z2) % P, (x2 - z2) % P
        aa, bb = a * a % P, b * b % P
        e = (aa - bb) % P
        c, d = (x3 + z3) % P, (x3 - z3) % P
        da, cb = d * a % P, c * b % P
        x3 = (da + cb) ** 2 % P
        z3 = x1 * (da - cb) ** 2 % P
        x2 = aa * bb % P
        z2 = e * (aa + A24 * e) % P
    if swap:
        x2, z2 = x3, z3
    return (x2 * pow(z2, P - 2, P) % P).to_bytes(32, "little")


def _self_test() -> None:
    """Vetores do RFC 7748, secao 6.1."""
    a = bytes.fromhex("77076d0a7318a57d3c16c17251b26645df4c2f87ebc0992ab177fba51db92c2a")
    b = bytes.fromhex("5dab087e624a8a4b79e17f8b83800ee66f3bb1292618b6fd1c2f8b27ff88e0eb")
    base = (9).to_bytes(32, "little")
    a_pub = x25519(a, base)
    b_pub = x25519(b, base)
    assert a_pub.hex() == "8520f0098930a754748b7ddcb43ef75a0dbf3a0d26381af4eba4a98eaa9b4e6a"
    assert b_pub.hex() == "de9edb7d7b7dc1b4d35b61c2ece435373f8343c85b78674dadfc7e146f882b4f"
    shared = "4a5d9d5ba4ce2de1728e3bf480350f25e07e21c947d19e3376f09b3c1e161742"
    assert x25519(a, b_pub).hex() == shared and x25519(b, a_pub).hex() == shared


def _fmt(k: bytes) -> str:
    h = [f"0x{v:02x}" for v in k]
    return "{ " + ", ".join(h[:16]) + ",\n      " + ", ".join(h[16:]) + " }"


def main() -> int:
    nodes = int(sys.argv[1]) if len(sys.argv) > 1 else 2
    path = sys.argv[2] if len(sys.argv) > 2 else "Inc/ecc_keys.h"
    if not 2 <= nodes <= 254:
        print("Numero de nos deve estar entre 2 e 254.", file=sys.stderr)
        return 1
    _self_test()

    base = (9).to_bytes(32, "little")
    privs = []
    for _ in range(nodes):
        k = bytearray(secrets.token_bytes(32))
        k[0] &= 248
        k[31] = (k[31] & 127) | 64
        privs.append(bytes(k))
    pubs = [x25519(k, base) for k in privs]

    today = datetime.date.today().isoformat()
    out = [
        f"/* Gerado em {today} por Tools/gerar_chaves_ecc.py. Contem chaves privadas: NAO versionar/compartilhar. */",
        "#ifndef ECC_KEYS_H", "#define ECC_KEYS_H", "", "#include <stdint.h>", "",
        f"/* ID deste no (1..{nodes}). Altere aqui ou defina -DNODE_ID=n nas opcoes do compilador. */",
        "#ifndef NODE_ID", "#define NODE_ID 1", "#endif", "",
        f"#define ECC_NUM_NODES {nodes}", "",
    ]
    for i, k in enumerate(privs):
        out.append(f"{'#if' if i == 0 else '#elif'} NODE_ID == {i + 1}")
        out.append("static const uint8_t ECC_NODE_PRIVATE_KEY[32] =")
        out.append("      " + _fmt(k) + ";")
    out += ["#else", '#error "NODE_ID invalido"', "#endif", "",
            "/* Chaves publicas dos nos permitidos; indice = NODE_ID - 1. */",
            "static const uint8_t ECC_NODE_PUBLIC_KEYS[ECC_NUM_NODES][32] = {"]
    for i, k in enumerate(pubs):
        out.append(f"  /* no {i + 1} */ " + _fmt(k) + ("," if i < nodes - 1 else ""))
    out += ["};", "", "#endif", ""]

    with open(path, "w", newline="\n") as f:
        f.write("\n".join(out))
    print(f"Chaves de {nodes} nos gravadas em {path}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
