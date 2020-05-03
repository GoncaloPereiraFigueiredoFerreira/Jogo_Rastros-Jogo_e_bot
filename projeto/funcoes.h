/**
@file funcoes.h
*/

#ifndef PL6_4_FUNCOES_H
#define PL6_4_FUNCOES_H

#include "dados.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
\brief Atualiza o estado após receber a coordenada
@param est Apontador para o estado
@param c Coordenada recebida
*/
void atualizaEstado (ESTADO *est, COORDENADA c);

/**
\brief Verifica se a jogada pretendida é valida e se for chama a função atualizaEstado para mudar o estado
@param est Apontador para o estado
@param c Coordenada recebida
*/
int jogar(ESTADO *est, COORDENADA c);

/**
\brief Função que volta a trás no jogo tantas jogadas quantas pretendidas 
@param jog Jogadas a recuar
@param est Apontador para o estado
*/
int jogAnt (int jog, ESTADO *est);

/**
\brief Função que cria um delay
@param msegundos Quantidade de segundos a que se pretende dar delay
*/
void delay(float msegundos);

#endif