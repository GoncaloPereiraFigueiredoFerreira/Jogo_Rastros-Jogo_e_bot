#ifndef PL6_4_FUNCOES_H
#define PL6_4_FUNCOES_H

#include "../dados/dados.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void atualizaEstado (ESTADO *est, COORDENADA c);
int jogar(ESTADO *est, COORDENADA c);
int jogAnt (int jog, ESTADO *est);
void delay(float msegundos);
#endif