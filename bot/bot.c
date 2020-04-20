#include "../Logica/funcoes.h"
#include "../interface/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int fill(ESTADO *est1){
	ESTADO *est = cpEst(est1);
	COORDENADA q[25],c;
	int x,y,j,j1,i = 0,t = 0,empty = 0;
	while (t >= 0){
		x = est->pos.x;
		y = est->pos.y;
		for(j = -1;j<2;j++)
			for(j1 = -1;j1<2;j1++){
				c.x = x+j;
				c.y = y+j1;
				if (x+j >= 0 && y+j1 >= 0 && x+j < 8 && y+j1 < 8 && check(est,c)){
					q[(i+t)%25] = c;
					est->tab[c.x][c.y] = '*';
					t++;
					empty++;  
				}
			}
		est->pos = q[i];
		i = (i+1)%25;
		t--;
	}
	return empty;
}

int dist(COORDENADA c,COORDENADA c1){
	return (c.x - c1.x)*(c.x - c1.x)+(c.y - c1.y)*(c.y - c1.y);}

int value(ESTADO *est,int jog){
	int player = est->jogador_atual;
	int total = 0;
	COORDENADA c;
	if (jog < 0) {
		player = (player)%2+1;
		total += (fill(est))%2 * 10;
	}
	else {total += (fill(est)+1)%2 * 10;}
	if (player == 1){
		c.x = 7;c.y = 0;}
	else {
		c.x = 0;c.y = 7;}
	total += dist(c,est->pos);
	return total;
}

int minmax (ESTADO *est,int jog,int depth,int max,int min,int *t){
	int n,score,mscore,i = 0;
	COORDENADA m[8];
	n = verificaFim(est);
	mscore = -MSCORE*jog*2;
	ESTADO *est1 = cpEst(est);
	if(n){
		if(est->jogador_atual == n) mscore = jog*MSCORE;
		else mscore = -jog*MSCORE;
		//printf("Final-%d   jog-%d   depth-%d  winner-%d\n",mscore,jog,depth,n);
	}
	else if(!depth) mscore = value(est,jog);
	else{
		n = movs(est,m);
		if (n == 1){atualizaEstado(est1,m[0]);mscore = minmax(est1,-jog,depth,max,min,t);}
		for(i = 0;i<n;i++){
			atualizaEstado(est1,m[i]);
			score = minmax(est1,-jog,depth-1,max,min,t);
//			printf("%d<%d\n",score*jog,mscore*jog);
			if (score*jog > mscore*jog) mscore = score;
			if (jog > 0) {if (max < score) max = score;}
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
	int n,i,score,mscore,min,max,t = 0,r = 0,depth;
	clock_t time = clock();
	COORDENADA m[8];
	ESTADO *est1;
	est1 = cpEst(est);
	n = movs(est,m);
	mscore = 0;
	max = -MSCORE;
	min = MSCORE;
	i = fill(est);
	printf("%d\n",fill(est));
	if (i>55) depth = DEPTH * 0.55;
	else if (i>45) depth = DEPTH * 0.6;
	else if (i>40) depth = DEPTH * 0.65;
	else if (i>35) depth = DEPTH * 0.80;
	else depth = DEPTH; 
	if (n == 1){free(est1);return m[0];}
	for(i = 0;i<n;i++){
		atualizaEstado(est1,m[i]);
		score = minmax(est1,-1,depth,max,min,&t);
		if (score > mscore) {mscore = score;r = i;}
		if (max < score) max = score;
		showCOORD(m[i]);
		printf("-%d, min = %d,max = %d,nodos = %d\n",score,min,max,t);
		if (max >= min) i = n; 
		t = 0;
		free(est1);
		est1 = cpEst(est);
	}
	free(est1);
	clock_t diff = (clock()-time);
	printf("tempo-%dms\n",diff*1000/CLOCKS_PER_SEC);
	return m[r];
}