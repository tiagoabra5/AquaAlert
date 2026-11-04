/**
  * @file    aquaalert_rf.h
  * @brief   Configuracao de RF do AquaAlert: camada fisica otimizada para
  *          comunicacao com salto de frequencia (FHSS) em 915-928 MHz.
  *
  *          Hardware: X-NUCLEO-S2915A1 = S2-LP + FEM Skyworks SKY66420-11
  *          (PA +27 dBm / ganho TX 16 dB / LNA 18 dB, NF ~2 dB; entrada TX
  *          maxima absoluta +17 dBm).
  *
  *          Perfil atual: parametros fisicos do firmware anterior (38,4 kbps,
  *          sem FEC, drive -4 dBm), validados entre duas placas na bancada.
  *          O perfil experimental de alcance maximo precisa de nova validacao
  *          de alimentacao/RF antes de ser reativado.
  *
  *          Regras de salto (ANATEL Ato 14448 / FCC 15.247 para banda de
  *          20 dB < 250 kHz): >= 50 canais, uso equilibrado, ocupacao media
  *          <= 0,4 s por canal a cada 20 s, potencia conduzida <= 1 W (30 dBm),
  *          antena <= 6 dBi sem reducao de potencia.
  */
#ifndef AQUAALERT_RF_H
#define AQUAALERT_RF_H

#include "S2LP_Radio.h"
#include "S2LP_PktBasic.h"

/* ---------------------------------------------------------------- Potencia */
/* Perfil de recuperacao: potencia usada pelo firmware anterior (PA = 0x25).
 * O ajuste de +12 dBm apresentou corrupcao de registradores durante TX
 * no teste de bancada. Validar alimentacao/RF antes de voltar a aumenta-lo. */
#define AA_FEM_DRIVE_DBM        -4
/* Potencia usada se nenhum FEM for detectado/forcado (S2-LP sozinho). */
#define AA_PA_DBM_NO_FEM        14
/* Slot de PA usado (PA_POWER8 quando 7). */
#define AA_PA_INDEX             7

/* ---------------------------------------------------------- Camada fisica */
#define AA_MODULATION           MOD_2FSK
#define AA_DATARATE             38400U    /* bps, perfil anterior do CubeIDE */
#define AA_FREQ_DEV             20000U    /* Hz */
/* Largura do filtro usada pelo firmware anterior. */
#define AA_CHANNEL_BW           100000U   /* Hz */
#define AA_PREAMBLE_BYTES       4U
#define AA_SYNC_WORD            0x88888888UL
#define AA_SYNC_BYTES           4U
#define AA_CRC_MODE             PKT_CRC_MODE_8BITS
#define AA_FEC                  S_DISABLE
#define AA_WHITENING            S_ENABLE

/* --------------------------------------------------- Salto de frequencia */
/* 50 canais de ~250 kHz de 915,375 a ~927,56 MHz (dentro de 915-928 MHz).
 * Com XTAL de 50 MHz o registrador de espacamento arredonda para ~248,7 kHz. */
#define AA_FHSS_BASE_HZ         915375000UL
#define AA_FHSS_SPACING_HZ      250000UL
#define AA_FHSS_CHANNELS        50U

/* Limite de ocupacao por canal (regra de salto) e janela de observacao. */
#define AA_FHSS_MAX_DWELL_MS    400U
#define AA_FHSS_WINDOW_MS       20000U

/* O receptor fica "estacionado" num canal e troca a cada AA_FHSS_PARK_MS.
 * Um alerta pode se perder se a troca cair no meio de uma varredura
 * (probabilidade ~ duracao_da_varredura / (2 * AA_FHSS_PARK_MS) ~ 0,6 %). */
#define AA_FHSS_PARK_MS         (10UL * 60UL * 1000UL)

/* Tempo maximo esperando o fim de um envio (CSMA + tempo no ar). */
#define AA_TX_TIMEOUT_MS        600U

#endif /* AQUAALERT_RF_H */
