#ifndef PL6_4_FUNCOES_H
#define PL6_4_FUNCOES_H

#include "../dados/dados.h"


void atualizaEstado (ESTADO *est, COORDENADA c);
int jogar(ESTADO *est, COORDENADA c);
void save(char cam[],ESTADO *est);
int jogAnt (int jog, ESTADO *est);


#endif