#ifndef PL6_4_FUNCOES_H
#define PL6_4_FUNCOES_H

#include "dados.h"

ESTADO* inicia();
int obter_jogador_atual(ESTADO *est);
void atualizaEstado (ESTADO *est, COORDENADA c);
int moves (ESTADO *est,COORDENADA mvs[8]);
int jogar(ESTADO *est, COORDENADA c);
int verificaFim (ESTADO *est);
int jogAnt (int jog, ESTADO *est);
int escolheVencedor(ESTADO *est);
#endif