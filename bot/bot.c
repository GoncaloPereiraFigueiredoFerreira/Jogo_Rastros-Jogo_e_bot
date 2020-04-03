#include "../Logica/funcoes.h"
#include "../interface/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include "bot.h"

ESTADO* cpEst(ESTADO *est){
	ESTADO *est1 = malloc(sizeof(ESTADO));
	int i,i1;
	for(i=0;i<8;i++)
		for(i1=0;i1<8;i1++)
			est1->tab[i][i1] = est->tab[i][i1];
	est1->pos.x = est->pos.x;
	est1->pos.y = est->pos.y;
	est1->num_jogadas = est->num_jogadas; 
	est1->jogador_atual = est->jogador_atual;
	return est1;
}

int max(int v[],int n,int jog){
	int i = n-1;
	for(n-=2;n>=0;n--){
		if (v[n]*jog>v[i]*jog) i = n;
	}
	return i;
}

int minmax(ESTADO *est,int jog,int depth){
	int v[8],n,i;
	COORDENADA m[8];
	n = verificaFim(est);
	if (n){
		if(jog*(est->jogador_atual) == n) i = -1;
		else i = 1; 
	}
	else if(!depth) i = 0;
	else{
		ESTADO *est1 = cpEst(est);
		n = jogPoss(est,m);
		for (i = 0;i<n;i++){
			jogar(est1,m[i]);
			v[i] = minmax(est1,-jog,depth-1);
			free(est1);
			est1 = cpEst(est);
		}
		free(est1);
		i = (v[max(v,n,jog)]);
	}
	return i;
}

COORDENADA bot (ESTADO *est){
	int n,i,v[8],jog = 1;
	COORDENADA m[8];
	ESTADO *est1;
	est1 = cpEst(est);
	n = jogPoss(est,m);
	for(i = 0;i<n;i++){
		jogar(est1,m[i]);
		v[i] = minmax(est1,jog,DEPTH);
		free(est1);
		est1 = cpEst(est);
	}
	free(est1);
	return m[max(v,n,jog)];
}