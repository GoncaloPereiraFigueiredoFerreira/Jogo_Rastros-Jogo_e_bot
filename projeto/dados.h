#ifndef _DADOS
#define _DADOS

#include <stdlib.h>
#include <stdio.h>
#include "listasligadas.h"
#include <math.h>

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
typedef enum {
VAZIO = '.', /**< Casa vazia*/
BRANCA = '*', /**< Casa branca*/
PRETA = '#' /**< Casa preta*/
} CASA;

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

/**
\brief Função que retorna uma jogada possivél com uma estratégia diferente à jog
@param est Apontador para o estado
*/
COORDENADA jog2(ESTADO *est);

/**
\brief Função que inicia o array de jogadas
@param est Apontador para o estado
@param i Local a partir do qual a função limpa o array
*/
void limpaArr(ESTADO *est,int i);

/**
\brief Função que calcula a distancia euclidiana 
@param a Apontador para a coordenada 
*/
double dist1 (COORDENADA *a);
#endif