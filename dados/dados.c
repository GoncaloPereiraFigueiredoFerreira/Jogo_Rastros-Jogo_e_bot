#include <stdlib.h>
#include <stdio.h>
#include "dados.h"

void inicia(ESTADO *est){ 
	int i,j;
	for(i = 0;i<8;i++)
		for(j = 0;j<8;j++)
			est->tab[i][j] = VAZIO;
	est->pos.x = 4;
	est->pos.y = 3;
	est->tab[4][3] = BRANCA;
	est->num_jogadas = 0;
	est->jogador_atual = 1;
}

int check (ESTADO *est,COORDENADA c){
	int x1 = est->pos.x;
	int y1 = est->pos.y;
	int x = c.x;
	int y = c.y;
	CASA novaCasa = est->tab[x][y]; 
	return (abs(x1-x)<=1 && abs(y1-y)<=1 && novaCasa != BRANCA && novaCasa != PRETA);
}

int jogPoss (ESTADO *est,COORDENADA mvs[8]){
	int x = est->pos.x, y = est->pos.y;
	int i,i1,n = 0;
	COORDENADA c;
	for(i = -1;i < 2;i++)
		for(i1 = -1; i1 < 2;i1++){
			c.x = x+i;
			c.y = y+i1;
			if (x+i >= 0 && y+i1 >= 0 && x+i < 8 && y+i1 < 8 && check(est,c))
				mvs[n++] = c;
		}
	return n;

}
int verificaFim (ESTADO *est){
	COORDENADA atual = est->pos;
	int col = atual.x, lin =atual.y;
	COORDENADA vizinhos[8];
	int caso=0;
	if (col == 0 && lin == 7) caso = 1;
	else if (col == 7 && lin == 0) caso = 2;
	else if (jogPoss(est,vizinhos)== 0) caso =3;
	return caso;

}
