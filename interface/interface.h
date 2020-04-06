#ifndef PL6_4_IMPRIMIR_H
#define PL6_4_IMPRIMIR_H

#include "../Logica/funcoes.h"
#include "../bot/bot.h"
#include <stdio.h>
#include <string.h>

#define MAX 100
#define BUF_SIZE 1024

/**
@file interface.h
*/

/**
\brief Escreve na consola a cordenada dada à função
@param c Coordenada 
*/
void showCOORD (COORDENADA c); 

/**
\brief Dá a informação atual do jogo
@param est Apontador para o estado
*/
void prompt (ESTADO *est); 

/**
\brief Desenha as linhas horizontais do tabuleiro 
*/
void desenhal(); 

/**
\brief Desenha o estado
@param est Apontador para o estado
*/
void desenha(ESTADO *est); 

/**
\brief Lê um ficheiro de texto onde se encontre um estado do jogo e recomeça o jogo com esse estado
@param cam Nome do ficheiro
@param est Apontador para o estado
*/
int read(char cam[],ESTADO *est); 

/**
\brief Responsável por aceitar os comandos do utilizador 
@param est Apontador para o estado
*/
int interpretador(ESTADO *est); 

/**
\brief Escreve no ficheiro o histórico de jogadas de um determinado estado
@param est Apontador para o estado
@param f Apontador para o ficheiro onde será escrito o histórico de jogadas
*/
void hist(ESTADO *est,FILE *f);

/**
\brief Guarda o estado do jogo atual num ficheiro de texto
@param cam Nome do ficheiro
@param est Apontador para o estado
*/
void save(char cam[],ESTADO *est);

/**
\brief Função que trata de criar a parte inicial do jogo
*/
void desenhoInicial ();

#endif