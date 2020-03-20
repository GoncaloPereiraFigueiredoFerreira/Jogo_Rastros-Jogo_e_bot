#include "dados.h"
#include <stdlib.h>
#include <stdio.h>


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

int check (ESTADO *est,COORDENADA c){
	int x1 = est->pos.x;
	int y1 = est->pos.y;
	int x = c.x;
	int y = c.y;
	CASA novaCasa = est->tab[x][y]; 
	return (abs(x1-x)<=1 && abs(y1-y)<=1 && novaCasa != BRANCA && novaCasa != PRETA);
}

int moves (ESTADO *est,COORDENADA mvs[8]){
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

 //Função q valida uma Jogada e a aplica
int jogar(ESTADO *est, COORDENADA c){
	if (check(est,c)){
		atualizaEstado (est,c);
		return 0;
	}
	else {printf("N\n");return 1;}  
}


void save(char cam[],ESTADO *est){
	FILE *f;
	int x,y;
	COORDENADA c;
	f = fopen(cam,"w");
	for (x = 0;x<8;x++){
		for (y = 0;y<8;y++){
			if (x == 7 && y == 0) fputc('2',f);
			else if (x == 0 && y == 7) fputc('1',f); 
			else fputc(est->tab[y][x],f);
		}
		fputc('\n',f);
	}
	y = est->num_jogadas;
	for(x = 0;x<y;x++){
		c = est->jogadas[x];
		if (!(x%2)) fprintf(f,"\n%d%d: ",((x/2)+1)/10,((x/2)+1)%10);
		fprintf(f,"%c%d ",c.x+'A',9-c.y);
	}
	fclose(f);
}

int verificaFim (ESTADO *est){
	COORDENADA atual = est->pos;
	int col = atual.x, lin =atual.y;
	COORDENADA vizinhos[8];
	int caso=0;
	if (col == 0 && lin == 7) caso = 1;
	else if (col == 7 && lin == 0) caso = 2;
	else if (moves(est,vizinhos)== 0) caso =3;
	return caso;

}


