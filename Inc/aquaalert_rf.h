/**
  * @file    aquaalert_rf.h
  * @brief   Configuracao de RF do AquaAlert: camada fisica otimizada para
  *          alcance maximo e salto de frequencia (FHSS) em 915-928 MHz.
  *
  *          Hardware: X-NUCLEO-S2915A1 = S2-LP + FEM Skyworks SKY66420-11
  *          (PA +27 dBm / ganho TX 16 dB / LNA 18 dB, NF ~2 dB; entrada TX
  *          maxima absoluta +17 dBm).
  *
  *          Racional de alcance (ver DOCUMENTACAO.md, secao "Alcance"):
  *          - Potencia: S2-LP entrega AA_FEM_DRIVE_DBM ao FEM -> ~+27 dBm na antena.
  *          - Sensibilidade: taxa baixa (4,8 kbps) + filtro de RX estreito +
  *            FEC + preambulo longo. O filtro nao e mais estreito porque as
  *            placas usam cristal (nao TCXO): precisa acomodar o erro de
  *            frequencia entre duas placas (~+-20 ppm relativos).
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
/* Potencia que o S2-LP entrega na entrada TX do SKY66420. 12 dBm + 16 dB de
 * ganho ~ +27 dBm (saturacao do FEM). Limite absoluto do FEM: +17 dBm.
 * Reduza aqui se usar antena com ganho > 6 dBi. */
#define AA_FEM_DRIVE_DBM        12
/* Potencia usada se nenhum FEM for detectado/forcado (S2-LP sozinho). */
#define AA_PA_DBM_NO_FEM        14
/* Slot de PA usado (PA_POWER8 quando 7). */
#define AA_PA_INDEX             7

/* ---------------------------------------------------------- Camada fisica */
#define AA_MODULATION           MOD_2GFSK_BT1
#define AA_DATARATE             4800U     /* bps */
#define AA_FREQ_DEV             4800U     /* Hz (indice de modulacao 2) */
/* Filtro de RX: sinal ~15 kHz + folga para erro de cristal entre placas.
 * Com o offset calibrado pela EEPROM (gHasEeprom = 1) pode cair para ~30 kHz
 * (~+3 dB de sensibilidade). */
#define AA_CHANNEL_BW           60000U    /* Hz */
#define AA_PREAMBLE_BYTES       8U
#define AA_SYNC_WORD            0x88888888UL
#define AA_SYNC_BYTES           4U
#define AA_CRC_MODE             PKT_CRC_MODE_16BITS_1
#define AA_FEC                  S_ENABLE  /* codigo convolucional: + ganho, 2x tempo no ar */
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
