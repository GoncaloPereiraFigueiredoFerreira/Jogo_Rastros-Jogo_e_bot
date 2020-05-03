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
void limpaArr(ESTADO *est,int i){
	for (;i<64;i++){
		est->jogadas[i].x = -1;
		est->jogadas[i].y = -1;
	}
}

int check (ESTADO *est,COORDENADA c){
	int x1 = est->pos.x;
	int y1 = est->pos.y;
	int x = c.x;
	int y = c.y;
	CASA novaCasa = est->tab[x][y]; 
	return (abs(x1-x)<=1 && abs(y1-y)<=1 && novaCasa != BRANCA && novaCasa != PRETA);
}

LISTA jogPoss (ESTADO *est){
	int x = est->pos.x, y = est->pos.y;
	int i,i1;
	COORDENADA c,*c1;
	LISTA l = criarL();
	for(i = -1;i < 2;i++)
		for(i1 = -1; i1 < 2;i1++){
			c.x = x+i;
			c.y = y+i1;
			if (c.x >= 0 && c.y >= 0 && c.x < 8 && c.y < 8 && check(est,c)){
				c1 = malloc(sizeof(COORDENADA));
				c1->x = c.x;
				c1->y = c.y;
				l = insereH(l,c1);
			}
		}
	return l;
}

int movs (ESTADO *est,COORDENADA mvs[8]){
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
	int jogadorAtual = est->jogador_atual;
	COORDENADA atual = est->pos;
	int col = atual.x, lin = atual.y;
	COORDENADA vizinhos[8];
	int caso=0;
	if (col == 0 && lin == 7) caso = 1;
	else if (col == 7 && lin == 0) caso = 2;
	else if (movs(est,vizinhos) == 0) caso = (jogadorAtual % 2) +1;
	return caso;
}

COORDENADA jog(ESTADO *est){
	COORDENADA *c,c1;
	LISTA l = jogPoss(est);
	c = (l->valor);
	c1.x = c->x;
	c1.y = c->y; 
	while (!vazia(l)){
		free(l->valor);
		l = removeH(l);
	}
	return c1;
}

double dist1 (COORDENADA *a){
	return (sqrt ( pow(7-(a->x),2) + pow(0-(a->y),2))); 
}

COORDENADA jog2 (ESTADO *est){
	LISTA L = jogPoss(est);
	COORDENADA *c, c1;
	c = (L->valor);
	c1=*c;
	double a = dist1 (&est->pos);
	while (L){
		if (est->jogador_atual == 1 && dist1(c)>a){
			c1=*c;
			a=dist1(c);
		}
		if (est->jogador_atual == 2 && dist1(c)<a){
			c1=*c;
			a=dist1(c);
		}
		L=L->prox;
		if (L) c=L->valor;
	}
	return c1;
}











/*
COORDENADA jog2(ESTADO *est){
	LISTA L = jogPoss(est);
	int i = sizeL(L);
	COORDENADA *c,c1,c2;
	c = L->valor;
	c1.x = c2.x = c->x;
	c1.y = c2.y = c->y;
	if (est->jogador_atual==1){
		while (L->prox){
			if (c1.x + c1.y <= c2.x + c2.y) {
				c2.x = c1.x;
				c2.y = c1.y;
			}
			L = L->prox;
			c = L->valor;
			c1.x=c->x;
			c1.y=c->y;
		}
	}
	else {
		while (L->prox){
			if ((c1.x+c1.y)>=(c2.x+c2.y)){
				c2.x = c1.x;
				c2.y = c1.y;
			} 
			L = L->prox;
			c = L->valor;
			c1.x=c->x;
			c1.y=c->y;
		}
	}
	while (!vazia(L)){
		free(L->valor);
		L = removeH(L);
	}
	return c2;
}

*/