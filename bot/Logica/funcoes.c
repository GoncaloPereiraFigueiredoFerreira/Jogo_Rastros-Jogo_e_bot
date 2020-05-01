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
