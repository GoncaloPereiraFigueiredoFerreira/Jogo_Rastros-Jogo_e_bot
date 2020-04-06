//Camada de Dados

#ifndef _DADOS
#define _DADOS

#include <stdlib.h>
#include <stdio.h>
#include "../Listas Ligadas/listasligadas.h"

/*! \mainpage Index
* 
* \section intro_sec Intruduction
*
* A interface é responsável por todas as funções que interagem com o jogador humano.
* A estrutura de dados, devolve a base para o nosso projeto defenindo e verificando o estado do jogo.
* Lógica é a camada referente as funções principais que definem as regras do Jogo.
*/

/**
@file dados.h
*/

/**
\brief Dados das varias casas 
*/
typedef enum {VAZIO = '.', BRANCA = '*', PRETA = '#'} CASA;

/**
\brief Dados das coordenadas 
*/
typedef struct {
int x; /**< Colunas*/
int y; /**< Linhas */
} COORDENADA;

/**
\brief Array com todas as posições ocupadas por peças pretas
*/
typedef COORDENADA JOGADAS[64];

/**
\brief Informação que o estado contem
*/
typedef struct {
	CASA tab[8][8]; /**< Matriz com o estado do tabuleiro */
	COORDENADA pos; /**< Posição da peça branca*/
	JOGADAS jogadas;/**< Jogadas */
	int num_jogadas; /**< Número de Jogadas Realizadas até agora*/
	int jogador_atual; /**< Qual o Jogador a Jogar*/
} ESTADO;

/**
\brief Função que coloca o estado na sua posição inicial
@param est Apontador para o estado
*/
void inicia(ESTADO *est);

/**
\brief Função que cria uma lista ligada das possiveis jogadas
@param Apontador para o estado
*/
LISTA jogPoss (ESTADO *est);

/**
\brief Dá o numero de jogadas possiveis e enche o array com essas jogadas
@param est Apontador para o estado
@param mvs Array onde as jogadas possivéis ficaram guardadas
*/
int movs(ESTADO *est,COORDENADA mvs[8]);

/**
\brief Vê se é possivél fazer uma jogada
@param est Apontador para o estado
@param c Jogada pretendida
*/
int check (ESTADO *est,COORDENADA c);

/**
\brief Verifica se algum dos jogadores já ganhou
@param est Apontador para estado
*/
int verificaFim (ESTADO *est);

/**
\brief Função que retorna um jogada possivel 
@param est Apontador para o estado
*/
COORDENADA jog(ESTADO *est);

void limpaArr(ESTADO *est,int i);//Função que inicia o array de jogadas
#endif