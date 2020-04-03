#ifndef _LLig
#define _LLig

#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
void* valor;
struct lligada *prox;
} *LISTA,Nodo;

LISTA criarL();
LISTA insereH(LISTA L, void *val);
void *devolveH(LISTA L);
LISTA proximo(LISTA L);
LISTA removeH(LISTA L);
int vazia(LISTA L);

#endif