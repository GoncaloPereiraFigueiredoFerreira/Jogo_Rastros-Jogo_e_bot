#ifndef PL6_4_IMPRIMIR_H
#define PL6_4_IMPRIMIR_H

#include "../Logica/funcoes.h"
#include "../bot/bot.h"
#include <stdio.h>
#include <string.h>

#define MAX 100
#define BUF_SIZE 1024

void showCOORD (COORDENADA c); //Escreve na consola a cordenada dada à função
void prompt (ESTADO *est); //Dá a informação atual do jogo
void desenhal(); //Desenha as linhas horizontais do tabuleiro 
void desenha(ESTADO *est); //Desenha o estado
int read(char cam[],ESTADO *est); //Lê um ficheiro de texto onde se encontre um estado do jogo e recomeça o jogo com esse estado
int interpretador(ESTADO *est); //Responsável por aceitar os comandos do utilizador 
void hist(ESTADO *est,FILE *f); //Escreve no ficheiro o histórico de jogadas de um determinado estado
void save(char cam[],ESTADO *est); //Guarda o estado do jogo atual num ficheiro de texto


#endif