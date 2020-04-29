#include "funcoes.h"

void atualizaEstado (ESTADO *est, COORDENADA c){
	int x1 = est->pos.x;
	int y1 = est->pos.y;
	    est->pos.x = c.x;
		est->pos.y = c.y;
		est->tab[x1][y1] = PRETA;
		est->tab[c.x][c.y] = BRANCA;
		est->jogadas[est->num_jogadas++] = c;
		est->jogador_atual = ((est->num_jogadas) % 2 + 1);
}

int jogar(ESTADO *est, COORDENADA c){
	if (check(est,c)){
		atualizaEstado (est,c);
		limpaArr(est,est->num_jogadas);
		return 0;
	}
	else return 1;
}

int jogAnt (int jog, ESTADO *est){
	int i = (est->num_jogadas) - 1;
	if (jog*2 > 64 || jog < 0 || (est->jogadas[(jog*2)-1].x==-1 && est->jogadas[(jog*2)-1].y==-1 )) return 0;
	else if (jog == 0) {inicia(est);return 1;}
	else if (jog*2 >i) {
		est->num_jogadas= jog*2;
		for (;i<(est->num_jogadas)-1;i++)
			est->tab[est->jogadas[i].x] [est->jogadas[i].y] =PRETA;}
	else if (jog*2 <=i){
		est->num_jogadas = jog*2;
		for (;i>=(est->num_jogadas);i--)
			est->tab[est->jogadas[i].x] [est->jogadas[i].y] =VAZIO;}

		est->tab[est->jogadas[i].x] [est->jogadas[i].y] = BRANCA;
		est->pos.x = est->jogadas[i].x;
		est->pos.y = est->jogadas[i].y;
		est->jogador_atual = 1;
	
	return 1;
}


void delay(float msegundos) { 
    int segundos = 1000 * msegundos;
    clock_t inicio = clock();
    while (clock() < inicio + segundos); 
}



/*
COORDENADA jog2(ESTADO *est){
    LISTA l = jogPoss(est);
    int v[sizeL(l)],i=0,i2;
    LISTA l2,l3=l;
    COORDENADA *c,c1;
    ESTADO *est2=cpEst(est);
    while (l3){
        c = (l3->valor);
        c1.x = c->x;
        c1.y = c->y;
        jogar(est2,c1);
        l2 =jogPoss(est2);
        v[i]=sizeL(l2);
        while (!vazia(l2)){
            free(l2->valor);
            l2 = removeH(l2);
        }
        l3= l3->prox;
        jogAnt(((est2->num_jogadas)-1),est2);
        i++;
    }
    i2=i;
    while (i!=1){
        if (v[i-1]<=v[i2]) i2=i-1;
        i--;
    }
    while (i2!=0 && l) {
        l=l->prox;
        i2--;
    }
    if (l->valor) {
        c = (l->valor);
        c1.x = c->x;
        c1.y = c->y;
    }
    while (!vazia(l)){
        free(l->valor);
        l = removeH(l);
    }
    while (!vazia(l3)){
        free(l3->valor);
        l3 = removeH(l3);
    }
    return c1;
}
*/