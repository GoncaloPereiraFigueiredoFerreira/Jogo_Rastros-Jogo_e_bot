#ifndef PL6_4_BOT_H
#define PL6_4_BOT_H

#include "interface/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include "Logica/funcoes.h"
#define DEPTH 20
#define MSCORE 100000

/*! \mainpage Index
* 
* \section intro_sec Intruduction
*
* Aqui podemos encontrar a documentação das nossas funções responsáveis por fazer o nosso bot escolher a melhor jogada possívell
*/

/**
@file bot.h
*/

/**
\brief Função que dado um estado cria um novo e copia a informação do estado dado
@param est Estado que se pretende copiar
*/
ESTADO* cpEst(ESTADO *est);

/**
\brief Dá um valor ao estado dado de forma a depois ser escolhido a jogada mais favoravel dependendo se o jog é -1 ou 1
@param est Apontador para o estado 
@param jog Valor que dita se é o jogador adversário a jogar (sendo jog=-1) ou o bot a jogar (1)
*/
int value(ESTADO *est,int jog);

/**
\brief Implementação da função MinMax
@param est Apontador para o estado
@param jog Valor que dita se é o jogador adversário a jogar (sendo jog=-1) ou o bot a jogar (1)
@param depth Profundidade máxima da árvore de escolhas 
@param max Valor máximo atribuido a um estado que a árvore consegui achar 
@param min Menor valor atribuido a um estado que a árvore consegui achar 
*/
int minmax (ESTADO *est,int jog,int depth,int max,int min,int *t);

/**
\brief Implementação da função Floodfill
@param est1 Apontador para o estado 
@param tab Tabuleiro que contem as distancias reais a cada peça 
*/
int fill(ESTADO *est1,int tab[8][8]);

/**
\brief Inicialização da função MinMax
@param est Apontador para o estado 
*/
COORDENADA bot (ESTADO *est);

#endif