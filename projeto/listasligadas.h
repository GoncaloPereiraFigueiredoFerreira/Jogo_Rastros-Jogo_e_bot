/**
@file listasligadas.h
*/

#ifndef _LLig
#define _LLig

#include <stdio.h>
#include <stdlib.h>

/**
\brief Struct das listas 
*/
typedef struct lligada {
void* valor; /**< Valor*/
struct lligada *prox; /**< Apontador para a próxima lista*/
} *LISTA,Nodo;

/**
\brief Cria uma lista 
*/
LISTA criarL(); 

/**
\brief Insere um valor na cabeça da lista
@param l Lista
@param val Apontador do valor a ser inserido
*/
LISTA insereH(LISTA L, void *val);
/**
\brief Devolve o valor da cabeça da lista
@param l Lista
*/
void *devolveH(LISTA L);

/**
\brief Devolve o próximo valor da lista
@param L Lista
*/
LISTA proximo(LISTA L);

/**
\brief Remove a cabeça da lista
@param L Lista
*/
LISTA removeH(LISTA L);

/**
\brief Devolve a tamanho da lista
@param L lista
*/
int sizeL(LISTA L);

/**
\brief Verifica se a lista está vazia
@param L Lista
*/
int vazia(LISTA L);

#endif