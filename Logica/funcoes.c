#include "../dados/dados.h"
#include <stdlib.h>
#include <stdio.h>



int escolheVencedor(ESTADO *est){ 
	int jogadorAtual = est->jogador_atual;
	int caso = verificaFim(est);
	if (caso == 3) caso = jogadorAtual;
	return caso;
}

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

 //Função q valida uma Jogada e a aplica
int jogar(ESTADO *est, COORDENADA c){
	if (check(est,c)){
		atualizaEstado (est,c);
		return 0;
	}
	else return 1;
}

int jogAnt (int jog, ESTADO *est){
	int i = est->num_jogadas;
	if (jog*2 > i || jog < 0) return 0;
	else if (jog == 0) inicia(est);
	else {
		est->num_jogadas = jog*2;
		for (i;i>=est->num_jogadas;i--)
			est->tab[est->jogadas[i].x] [est->jogadas[i].y] =VAZIO;
		est->tab[est->jogadas[i].x] [est->jogadas[i].y] = BRANCA;
		est->pos.x = est->jogadas[i].x;
		est->pos.y = est->jogadas[i].y;
		est->jogador_atual = 1;
	}
	return 1;
}

