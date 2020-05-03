#include "listasligadas.h"

LISTA criarL(){
	LISTA l = malloc (sizeof(Nodo));
	l->valor =NULL;
	l->prox = NULL;
	return l;
}

LISTA insereH(LISTA L, void *val){
	if (L->prox || L->valor){
		LISTA x= criarL(); 
		x->valor=val;
		x->prox=L;
		return x;
	}
	else L->valor=val;
	return L;
}

void *devolveH(LISTA L){
	return (L->valor);
}

LISTA proximo(LISTA L){
	return (L->prox);
}
LISTA removeH(LISTA L){
	LISTA a=L->prox;
	free (L);
	return a;
}

int sizeL(LISTA L){
	int i=0;
	while (L) {
	i++;
	L=L->prox;
	}
	return i;
}

int vazia(LISTA L){
	return (L)?0:1;
}