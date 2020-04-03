#ifndef PL6_4_FUNCOES_H
#define PL6_4_FUNCOES_H

#include "../dados/dados.h"
#include <stdlib.h>
#include <stdio.h>

void atualizaEstado (ESTADO *est, COORDENADA c); //Atualiza o estado após uma jogada ter sido feita
int jogar(ESTADO *est, COORDENADA c); // Função que valida uma Jogada e a aplica
int jogAnt (int jog, ESTADO *est); //Volta a trás no jogo para uma jogada escolhida


#endif