//Camada de Dados

#ifndef _DADOS
#define _DADOS

#include <stdlib.h>
#include <stdio.h>
#include "../Listas Ligadas/listasligadas.h"

typedef enum {VAZIO = '.', BRANCA = '*', PRETA = '#'} CASA;

typedef struct {
int x; // Colunas
int y; // Linhas
} COORDENADA;

// Array com todas as posições ocupadas por peças pretas
typedef COORDENADA JOGADAS[64];

typedef struct {
	CASA tab[8][8]; // Estado Do Tabuleiro
	COORDENADA pos; // Posicção da Peça Branca
	JOGADAS jogadas; // Lista de Jogadas ja Feitas || Peças Pretas 
	int num_jogadas;  // Número de Jogadas Realizadas até agora
	int jogador_atual; // Qual o Jogador a Jogar
} ESTADO;


void inicia(ESTADO *est);//Função que coloca o estado na sua posição inicial
LISTA jogPoss (ESTADO *est);//Função que cria uma lista ligada das possiveis jogadas
int movs(ESTADO *est,COORDENADA mvs[8]);//Dá o numero de jogadas possiveis e enche o array com essas jogadas
int check (ESTADO *est,COORDENADA c);//Vê se é possivél fazer uma jogada
int verificaFim (ESTADO *est);//Verifica se algum dos jogadores já ganhou
COORDENADA jog(ESTADO *est);//Função que retorna um jogada possivel
void limpaArr(ESTADO *est,int i);//Função que inicia o array de jogadas
#endif