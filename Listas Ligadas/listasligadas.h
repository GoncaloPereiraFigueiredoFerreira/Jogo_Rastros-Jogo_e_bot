#ifndef _LLig
#define _LLig

#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
void* valor;
struct lligada *prox;
} *LISTA,Nodo;

LISTA criarL(); //Cria uma lista 
LISTA insereH(LISTA L, void *val); //Insere um valor na cabeça da lista 
void *devolveH(LISTA L); //Devolve o valor da cabeça da lista
LISTA proximo(LISTA L); //Devolve o próximo valor da lista
LISTA removeH(LISTA L); //Remove a cabeça da lista
int vazia(LISTA L); //Verifica se a lista está vazia

#endif