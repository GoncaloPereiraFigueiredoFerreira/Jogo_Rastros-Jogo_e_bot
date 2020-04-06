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
/*
int minmax(ESTADO *est,int jog,int depth){
	int v[8],n,i,score,mscore;
	COORDENADA m[8];
	n = verificaFim(est);
	if (n){
		if((est->jogador_atual) == n) mscore = -1*jog;
		else mscore = 1*jog; 
	}
	else if(!depth) mscore = 0;
	else{
		ESTADO *est1 = cpEst(est);
		n = movs(est,m);
		mscore = -2*jog;
		for (i = 0;i<n;i++){
			jogar(est1,m[i]);
			score = minmax(est1,-jog,depth-1);
			if(score*jog>mscore*jog) mscore = score;
			//printf("%d\n",mscore);
			free(est1);
			est1 = cpEst(est);
		}
		free(est1);
	}
	return mscore;
}*/

int minmax (ESTADO *est,int jog,int depth,int max,int min,int *t){
	int n,score,mscore,i;
	COORDENADA m[8];
	n = verificaFim(est);
	mscore = 0;
	ESTADO *est1 = cpEst(est);
	if(n){
		if(est->jogador_atual == n) mscore = jog;
		else mscore = -jog;
	}
	else if(!depth) mscore = 0;
	else{
		n = movs(est,m);
		for(i = 0;i<n;i++){
			jogar(est1,m[i]);
			score = minmax(est1,-jog,depth-1,max,min,t);
			if (score*jog > mscore*jog) mscore = score;
			if (jog > 0) if (max < score) max = score;
			else if (min > score) min = score;
			if (max >= min) i = n; 
			free(est1);
			est1 = cpEst(est);
			(*t)++;
		}
		free(est1);
	}
	return mscore;
}

COORDENADA bot (ESTADO *est){
	int n,i,score,mscore,min,max,t = 0,r = 0;
	COORDENADA m[8];
	ESTADO *est1;
	est1 = cpEst(est);
	n = movs(est,m);
	mscore = 0;
	max = -MSCORE;
	min = MSCORE;
	for(i = 0;i<n;i++){
		jogar(est1,m[i]);
		score = minmax(est1,-1,DEPTH,max,min,&t);
		if (score > mscore) {mscore = score;r = i;}
		if (max < score) max = score;
		if (max >= min) i = n; 
		showCOORD(m[i]);
		printf("-%d, min = %d,max = %d,nodos = %d\n",score,min,max,t);
		free(est1);
		est1 = cpEst(est);
	}
	free(est1);
	return m[r];
}