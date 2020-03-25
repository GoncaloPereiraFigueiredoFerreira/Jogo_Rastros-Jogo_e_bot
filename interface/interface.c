#include "../Logica/funcoes.h"
#include "interface.h"
#include <stdio.h> 
#include <string.h>



void showCOORD (COORDENADA c){
	int letra = c.x;
	int linha = c.y;
	printf ("%c%d",(char)(letra+'A'),8-linha);
}

void prompt (ESTADO *est){
	int nJogada= est-> num_jogadas;
	int jogador= est->jogador_atual;
	COORDENADA atual = est-> pos;
	printf ("# %d PL%d (%d)>",nJogada,jogador,(nJogada/2)+1);
	showCOORD (atual);
	putchar('\n');
}


void desenhal(){
	printf("  ");
	for(int i = 0;i<8;i++) printf("+---");
	putchar('+');
	putchar('\n');
}

void desenha(ESTADO *est){
	char c;	
	prompt(est);
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

}

void hist(ESTADO *est,FILE *f){
	int i;
	COORDENADA c;
	for(i = 0;i<(est->num_jogadas);i++){
		c = est->jogadas[i];
		if (!(i%2)) fprintf(f,"\n%02d: ",i+1);
		fprintf(f,"%c%d ",c.x+'A',8-c.y);
	}
	fputc('\n',f);
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
	hist(est,f);
	fclose(f);
}

int interpretador(ESTADO *est) {
	char linha[BUF_SIZE],cam[BUF_SIZE];
	char col[2], lin[2];
	int i;
	if (verificaFim(est) != 0){ 
		printf("Parabens player %d, Ganhaste !!!\n", escolheVencedor(est));
		return 0;
	}	
	else if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;	
	else if(strlen(linha) == 3 && sscanf(linha, "%[A-H]%[1-8]", col, lin) == 2) {
		COORDENADA coord = {*col -'A',7-(*lin -'1')};
		if (jogar(est, coord)) printf("Jogada invalida\n");
		else desenha(est);
	}
	else if (strcmp(linha,"poss\n") == 0){
		COORDENADA c[8];
		int n = jogPoss(est,c);
		for(int i = 0; i < n;i++) {showCOORD(c[i]);putchar(' ');}
		putchar('\n'); 
	}
	else if (strcmp(linha,"movs\n") == 0) hist(est,stdout);
	else if (sscanf(linha,"gr %s",cam) == 1){
		save(cam,est);
		printf("O seu jogo foi salvo\n");
	}
	else if (sscanf(linha,"pos %d",&i) == 1) {
		jogAnt(i,est);
		desenha(est);
	}
	else if (linha[0] == 'Q') return 0;
	return 1;
}