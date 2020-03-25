#include "../Logica/funcoes.h"
#include "interface.h"
#include <stdio.h> 
#include <string.h>



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

void read (char cam[],ESTADO *est){	
	FILE *f;
	char linha[10];
	COORDENADA c;
	int i=0,i2=0;
	f = fopen (cam,"r");
	while (i!=8){
		fscanf(f,"%s",linha);
		while (i2!=8){
			if (linha[i2] == '#')
			est->tab[i][i2] = linha[i2];
			else if (linha[i2]== '*')
			est->tab[i][i2] = linha[i2];
			else est->tab[i][i2]=VAZIO;
			i2++;
		}
		i++;
		fscanf(f,"\n");
	}
	i=0;
	fscanf(f,"\n");
	fscanf(f,"%s",linha);
	while (!feof(f)) {
		fscanf(f,"\n");
		fscanf(f,"%s",linha);
		c = est->jogadas[i];
		if (linha[5]!=EOF) {
			c.x = linha[5];
			c.y = linha[6];
			i++;
		}
		if (linha[9]!=EOF){
			c.x = linha[8];
			c.y = linha[9];
			i++;
		}
	}
	desenha(est);
	interpretador(est);
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


int interpretador(ESTADO *est) {
	char linha[BUF_SIZE],cam[BUF_SIZE];
	char col[2], lin[2];
	if (verificaFim(est) != 0){ 
		printf("Parabens player %d, Ganhaste !!!\n", escolheVencedor(est));
		return 0;
	}
	
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
	else if (sscanf(linha,"ler %s",cam) == 1){
		read(cam,est);
	}
	else if (sscanf(linha,"gr %s",cam) == 1){
		save(cam,est);
	}
	else if (linha[0] == 'Q') return 0;
	return 1;
}
