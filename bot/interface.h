#ifndef PL6_4_IMPRIMIR_H
#define PL6_4_IMPRIMIR_H

#include "funcoes.h"
#include <stdio.h>
#include <string.h>

#define MAX 100
#define BUF_SIZE 1024

/**
@file interface.h
*/

/**
\brief Lê um ficheiro de texto onde se encontre um estado do jogo e recomeça o jogo com esse estado
@param cam Nome do ficheiro
@param est Apontador para o estado
*/
int read(char cam[],ESTADO *est); 

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

#endif