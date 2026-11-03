/**
  * @file    fhss.h
  * @brief   Salto de frequencia (FHSS) do AquaAlert.
  *
  *          Esquema assincrono, sem sincronismo de relogio entre placas:
  *          - TX: cada alerta e enviado uma vez em CADA um dos AA_FHSS_CHANNELS
  *            canais, numa ordem pseudoaleatoria (varredura). Todos os canais
  *            sao usados igualmente.
  *          - RX: o receptor escuta um unico canal ("estacionado") e troca para
  *            outro canal sorteado a cada AA_FHSS_PARK_MS. Ele pega a copia
  *            transmitida no seu canal; copias repetidas (mesmo contador) sao
  *            recusadas pelo anti-replay do secure_link.
  *          - Ocupacao: antes de cada varredura, confere que a soma do tempo no
  *            ar por canal nos ultimos AA_FHSS_WINDOW_MS nao passa de
  *            AA_FHSS_MAX_DWELL_MS.
  */
#ifndef FHSS_H
#define FHSS_H

#include <stdint.h>

/* Monta a tabela de canais embaralhada. seed deve variar entre placas. */
void FHSS_Init(uint32_t seed);

/* Canal do passo i (0..AA_FHSS_CHANNELS-1) de uma varredura que comeca em start. */
uint8_t FHSS_SweepChannel(uint8_t start, uint8_t i);

/* Canal ou inicio de varredura sorteado (0..AA_FHSS_CHANNELS-1). */
uint8_t FHSS_RandomChannel(void);

/* Estimativa conservadora (com margem) do tempo no ar de um quadro com
 * payloadLen bytes, considerando preambulo, sync, comprimento, CRC e FEC. */
uint32_t FHSS_AirtimeMs(uint8_t payloadLen);

/* 1 se uma varredura que ocupa dwellMs em cada canal cabe no limite de
 * ocupacao agora; 0 caso contrario. */
uint8_t FHSS_SweepAllowed(uint32_t nowMs, uint32_t dwellMs);

/* Registra uma varredura iniciada em nowMs ocupando dwellMs por canal. */
void FHSS_RecordSweep(uint32_t nowMs, uint32_t dwellMs);

#endif /* FHSS_H */
