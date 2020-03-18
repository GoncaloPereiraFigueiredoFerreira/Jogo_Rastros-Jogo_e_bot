#include "funcoes.h"
#include <stdio.h> 
#include <string.h>
#define BUF_SIZE 1024

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
			else if (est->tab[x][y] == BRANCA) c = '*';
			else if (est->tab[x][y] == PRETA) c = '#';
			else if (est->tab[x][y] == VAZIO) c = '.';
			printf("| %c ",c);
		}
		putchar('|');
		putchar('\n');
	}
	desenhal();
}

int interpretador(ESTADO *est) {
	char linha[BUF_SIZE];
	char col[2], lin[2];
	if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
	else if(strlen(linha) == 3 && sscanf(linha, "%[A-H]%[1-8]", col, lin) == 2) {
		COORDENADA coord = {*col -'A',7-(*lin -'1')};
		jogar(est, coord);
		desenha(est);
	}
	else if (linha[0] == 'Q') return 0;
	return 1;
}