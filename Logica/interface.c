#include "funcoes.h"
#include <stdio.h> 
#include <string.h>
#define BUF_SIZE 1024




void showCOORD (COORDENADA c){
	int letra = c.x;
	int linha = c.y;
	printf ("%c%d\n",(char)(letra+'A'),8-linha);
}

void prompt (ESTADO *est){
	int nJogada= est-> num_jogadas;
	int jogador= est->jogador_atual;
	COORDENADA atual = est-> pos;
	printf ("# %d PL%d (%d)>",nJogada,jogador,(nJogada+1)/2);
	showCOORD (atual);
}


void desenhal(){ 
	printf("  ");
	for(int i = 0;i<8;i++) printf("+---");
	putchar('+');
	putchar('\n');
}

void desenha(ESTADO *est){
	char c;
	printf("    A   B   C   D   E   F   G   H\n");
	for(int y = 0;y< 8;y++){
		desenhal();
		printf("%d ",8-y);
		for(int x = 0;x< 8;x++){
			if (x == 7 && y == 0) c = '2';
			else if (x == 0 && y == 7) c = '1'; 
			else c = est->tab[x][y];
			printf("| %c ",c);
		}
		putchar('|');
		putchar('\n');
	}
	desenhal();
	prompt(est);
}
int escolheVencedor(ESTADO *est){ 
	int jogadorAtual = est->jogador_atual;
	int caso = verificaFim(est);
	if (caso == 3) caso = jogadorAtual;
	return caso;
}

int interpretador(ESTADO *est) {
	char linha[BUF_SIZE],cam[BUF_SIZE];
	char col[2], lin[2];
	if (verificaFim(est) != 0){ 
	printf("Parabens player %d, Ganhaste !!!\n", escolheVencedor(est));
	return 0;}
	
	else if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
	
	else if(strlen(linha) == 3 && sscanf(linha, "%[A-H]%[1-8]", col, lin) == 2) {
		COORDENADA coord = {*col -'A',7-(*lin -'1')};
		jogar(est, coord);
		desenha(est);
	}
	else if (strcmp(linha,"movs\n") == 0){
		COORDENADA c[8];
		int n = moves(est,c);
		for(int i = 0; i < n;i++) showCOORD(c[i]); 
	}
	else if (sscanf(linha,"gr %s",cam) == 1){
		save(cam,est);
	}
	else if (linha[0] == 'Q') return 0;
	return 1;
}
