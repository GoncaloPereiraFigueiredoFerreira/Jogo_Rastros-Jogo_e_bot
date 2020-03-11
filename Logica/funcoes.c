#include "dados.c"
#include <stdlib.h>
#include <math.h>

ESTADO* inicia(){
	ESTADO *est = (ESTADO *) malloc(sizeof(ESTADO)); 
	int i,j;
	for(i = 0;i<8;i++)
		for(j = 0;j<8;j++){
			est->tab[i][j] = VAZIO;
		} 
	est->pos.x = 4;
	est->pos.y = 3;
	est->tab[4][3] = BRANCA;
	est->num_jogadas = 0;
	est->jogador_atual = 1;
	return est;
}
// Made by Ganso
int obter_jogador_atual(ESTADO *est){
	int a;
	if (est->num_jogadas % 2 == 0) a=1; 
	else a= 2;
	return a;  
}
void atualizaEstado (ESTADO *est, COORDENADA c){
	int x1 = est->pos.x;
	int y1 = est->pos.y;
	    est->pos.x = c.x;
		est->pos.y = c.y;
		est->tab[x1][y1] = PRETA;
		est->tab[c.x][c.y] = BRANCA;
		est->jogadas[est->num_jogadas++] = c;
		est->jogador_atual = obter_jogador_atual (est);
}

 //Função q valida uma Jogada e a aplica
int jogar(ESTADO *est, COORDENADA c){
	int x1 = est->pos.x;
	int y1 = est->pos.y;
	int x = c.x;
	int y = c.y;
	CASA novaCasa = est->tab[x][y];
	
	if ( abs(x1-x)<=1 && abs(y1-y)<=1 && novaCasa != BRANCA && novaCasa != PRETA ){
		atualizaEstado (est,c);
		return 0;
	}
	else {printf("N\n");return 1;}  
}


