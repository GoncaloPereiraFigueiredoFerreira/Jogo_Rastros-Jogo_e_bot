#include <stdio.h> 
#include <string.h>
#define BUF_SIZE 1024


#include "Logica/funcoes.c"

void desenhal(){ 
	printf("  ");
	for(int i = 0;i<8;i++) printf("+---");
	putchar('+');
	putchar('\n');
}

void desenha(ESTADO *est){
	char c;
	printf("    A   B   C   D   E   F   G   H\n");
	for(int i = 0;i!=8;i++){
		desenhal();
		printf("%d ",i+1);
		for(int j = 0;j!= 8;j++)
			if (j == 0 && i == 7) c = '2';
			else if (j == 7 && i == 0) c = '1'; 
			else if (e->tab[i][j] == BRANCA) c = '*';
			else if (e->tab[i][j] == PRETA) c = '#';
			else if (e->tab[i][j] == VAZIA) c = '.';
			printf("| %c ",c);
		putchar('|');
		putchar('\n');
	}
	desenhal();
}

int interpretador(ESTADO *e) {
	char linha[BUF_SIZE];
	char col[2], lin[2];
	if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
	else if(strlen(linha) == 3 && sscanf(linha, "%[A-H]%[1-8]", col, lin) == 2) {
		COORDENADA coord = {*col -'a', *lin -'1'};
		jogar(e, coord);
		desenha(e);
	return 1;
}
}


int main() {
	ESTADO* estIN =inicia(); 
	desenha(estIN);
	return 0;
}
