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
}

int obter_jogador_atual(ESTADO *est){
	int a;
	if (est->num_jogadas % 2 == 0) a=1; 
	else a= 2;
	return a;  
}

//ESTADO atualizaEstado (ESTADO *est){
//	return est;

//}
 //Função q valida uma Jogada e a aplica
int jogar(ESTADO *est, COORDENADA c){
	int x1 = est->pos.x;
	int y1 = est->pos.y;
	int x = c.x;
	int y = c.y;
	
	if ( abs(x1-x)<=1 && abs(y1-y)<=1 && (abs(x1-x)!=0 || abs(y1-y)!=0) ){
		est->pos.x = x;
		est->pos.y = y;
		est->tab[x1][y1] = PRETA;
		est->tab[x][y] = BRANCA;
		est->jogadas[est->num_jogadas++] = c;
		return 0;
	}
	else {printf("N\n");return 1;}  
}