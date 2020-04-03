#include "listasligadas.h"

LISTA criarL(){
	LISTA l = malloc (sizeof(Nodo));
	l->valor =NULL;
	l->prox = NUll;
	return l;
}

LISTA insereH(LISTA L, void *val){
	
	if (L->prox){
		LISTA x= criar_lista(); 
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
	free (l);
	return a;
}
int vazia(LISTA L){
	return (int)(L->valor);
}