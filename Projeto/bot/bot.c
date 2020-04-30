#include "../Logica/funcoes.h"
#include "../interface/interface.h"
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

int fill(ESTADO *est1,int tab[8][8]){
	ESTADO *est = cpEst(est1);
	COORDENADA q[25],c;
	int x,y,j,j1,i = 0,t = 0,empty = 0;
	for(x = 0;x<8;x++)
		for(y = 0;y<8;y++) tab[x][y] = 64;
	tab[est->pos.x][est->pos.y]=0;
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
					if (tab[x][y]+1<tab[c.x][c.y]) tab[c.x][c.y] = tab[x][y] + 1;
//	for (x1 = 0;x1<8;x1++){for(y1 = 0;y1<8;y1++) printf("%2d,",tab[y1][x1]);putchar('\n');}putchar('\n');}
				}
			}
		est->pos = q[i];
		i = (i+1)%25;
		t--;
	}
	free(est);
	return empty;
}

int dist(COORDENADA c,COORDENADA c1){
	return (c.x - c1.x)*(c.x - c1.x)+(c.y - c1.y)*(c.y - c1.y);}

int value(ESTADO *est,int jog,int gen[]){
	int player = est->jogador_atual;
	int tab[8][8],f,total = 0;
	//COORDENADA c;
	f = fill(est,tab);
	if (jog < 0) {
		player = (player)%2+1;
		total += f%2*(gen[0]+gen[7]*f);
	}
	else {total += (f+1)%2*(gen[0]+gen[7]*f);}
	if (player == 1){
		if(tab[0][7] == 64) total += gen[1];
		else total -= tab[0][7]*gen[3]+gen[4];
		if(tab[7][0] == 64) total -= gen[2];
		else total += tab[7][0]*gen[5]+gen[6];
	}
	else {
		if(tab[7][0] == 64) total += gen[1];
		else total -= tab[7][0]*gen[3]+gen[4];
		if(tab[0][7] == 64) total -= gen[2];
		else total += tab[0][7]*gen[5]+gen[6];
	}
	return total;
}

int minmax (ESTADO *est,int jog,int depth,int max,int min,int *t,int gen[]){
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
	else if(!depth) mscore = value(est,jog,gen);
	else{
		n = movs(est,m);
		if (n == 1){atualizaEstado(est1,m[0]);mscore = minmax(est1,-jog,depth,max,min,t,gen);}
		else{
			for(i = 0;i<n;i++){
				atualizaEstado(est1,m[i]);
				score = minmax(est1,-jog,depth-1,max,min,t,gen);
	//			printf("%d<%d\n",score*jog,mscore*jog);
				if (score*jog > mscore*jog) mscore = score;
				if (jog > 0) {if (max < score) max = score;}
				else if (min > score) min = score;
				if (max >= min) i = n; 
				free(est1);
				est1 = cpEst(est);
				(*t)++;
			}
		}
	}
	free(est1);
	return mscore;
}

COORDENADA bot (ESTADO *est,int gen[]){
	int n,i,score,mscore,min,max,t = 0,r = 0,depth,tab[8][8];
//	clock_t time = clock();
	COORDENADA m[8];
	ESTADO *est1;
	est1 = cpEst(est);
	n = movs(est,m);
	mscore = -MSCORE;
	max = -MSCORE;
	min = MSCORE;
	i = fill(est,tab);
//	printf("%d\n",i);
/*	
	if (i == 63) depth = DEPTH *0.45;
	else if (i>55) depth = DEPTH * 0.5;
	else if (i>45) depth = DEPTH * 0.55;
	else if (i>35) depth = DEPTH * 0.60;
	else if (i>30) depth = DEPTH * 0.70;
	else depth = DEPTH;
*/
	depth = 0;
//	printf("%d\n",depth); 
	if (n == 1){free(est1);return m[0];}
	for(i = 0;i<n;i++){
		atualizaEstado(est1,m[i]);
		score = minmax(est1,-1,depth,max,min,&t,gen);
		if (score > mscore) {mscore = score;r = i;}
		if (max < score) max = score;
//		showCOORD(m[i]);printf("-%d, min = %d,max = %d,nodos = %d\n",score,min,max,t);
		if (max >= min) i = n; 
		t = 0;
		free(est1);
		est1 = cpEst(est);
	}
	free(est1);
//	clock_t diff = (clock()-time);
//	printf("tempo-%ldms\n",diff*1000/CLOCKS_PER_SEC);
	return m[r];
}