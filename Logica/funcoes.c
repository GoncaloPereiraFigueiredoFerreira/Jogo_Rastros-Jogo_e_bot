#include "dados.c"
#include <stdlib.h>

ESTADO* inicia(){
	ESTADO *est = (ESTADO *) malloc(sizeof(ESTADO)); 
	int i,j;
	for(i = 0;i<8;i++)
		for(j = 0;i<8;j++){
			est->tab[i][j] = VAZIO;

		} 
	est->pos.x = 4;
	est->pos.y = 3;
	est->tab[4][3] = BRANCA;
	est->num_jogadas = 0;
	est->jogador_atual = 1;
}

int obter_jogador_atual(ESTADO *est){
	int a;
	if (est.num_jogadas % 2 = 0) a=1; 
	else a= 2;
	return a;  
}

ESTADO atualizaEstado (Estado *est){

}

