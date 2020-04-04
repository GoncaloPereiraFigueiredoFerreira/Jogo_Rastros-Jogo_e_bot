#include "interface.h"

void showCOORD (COORDENADA c){
	int letra = c.x;
	int linha = c.y;
	printf ("%c%d",(letra+'A'),8-linha);
}

void prompt (ESTADO *est){
	int nJogada= est-> num_jogadas;
	int jogador= est->jogador_atual;
	COORDENADA atual = est-> pos;
	printf ("\n # %d PL%d (%d)>",nJogada,jogador,(nJogada/2)+1);
	showCOORD (atual);
	putchar('\n');
}
void desenhoInicial (){
	int i=3;
	printf("Bem vindo ao nosso Jogo Rastros\n\n");
	delay(2);
	printf("A carregar Jogo");
	for(;i>0;i--){
		delay(0.5);
		putchar('.');
	}
	delay(0.5);
	putchar ('\n');
}


void desenhal(){
	printf("   ");
	for(int i = 0;i<8;i++) printf("+---");
	putchar('+');
	putchar('\n');
}

void desenha(ESTADO *est){
	char c;	
	prompt(est);
	printf("     A   B   C   D   E   F   G   H\n");
	for(int y = 0;y< 8;y++){
		desenhal();
		printf(" %d ",8-y);
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
	putchar('\n');

}

void hist(ESTADO *est,FILE *f){
	int i;
	COORDENADA c;
	for(i = 0;i<(est->num_jogadas);i++){
		c = est->jogadas[i];
		if (!(i%2)) fprintf(f,"\n%02d: ",(i/2)+1);
		fprintf(f,"%c%d ",c.x+'a',8-c.y);
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
			if (x == 7 && y == 0) fputc('1',f);
			else if (x == 0 && y == 7) fputc('2',f); 
			else fputc(est->tab[y][x],f);
		}
		fputc('\n',f);
	}
	y = est->num_jogadas;
	hist(est,f);
	fclose(f);
}

int read(char cam[],ESTADO *est){
	FILE *f;
	f = fopen(cam,"r");
	int i,i1;
	int x,y,c = 0;
	if (f != NULL){
		for (i = 0;i<8;i++){
			fgets(cam,MAX,f);
			for(i1 = 0;cam[i1]!='\n';i1++){
				if (cam[i1] == '1' || cam[i1] == '2') est->tab[i][i1] = '.';
				else { est->tab[i1][i] = cam [i1];
					if (cam[i1] == '*') {
						est->pos.x = i1;
						est->pos.y = i;
					}
				}
			}
		}
		while (fgets(cam,BUF_SIZE,f) != NULL){
			for(i1 = 3;cam[i1]!='\0';i1++){
				if(cam[i1]>='a'&&cam[i1]<'i'){
					est->jogadas[c].x = cam[i1]-'a';
					est->jogadas[c++].y = 7-(cam[++i1]-'1');
				}
			}
		}
		est->num_jogadas = c;
		est->jogador_atual = (c%2)+1;
		fclose(f);
		return 0;
	}
	else return 1;
}

int interpretador(ESTADO *est) {
	char linha[BUF_SIZE],cam[BUF_SIZE];
	char col[2], lin[2];
	int i;
	if (verificaFim(est) != 0){ 
		printf("Parab%cns player %d, Ganhaste !!!\n\n",130, verificaFim(est));//130 = é em ASCII
		return 0;
	}	
	else if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;	
	else if((strlen(linha) == 3 && sscanf(linha, "%[A-H]%[1-8]", col, lin) == 2) || (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2)) {
		COORDENADA coord; 
		if (*col<73) {coord.x =*col -'A'; coord.y=7-(*lin -'1');}
		else {coord.x=*col -'a'; coord.y=7-(*lin -'1');}
		if (jogar(est, coord)) printf("\nJogada inv%clida...\n\n",160);//160 = á em ASCII
		else desenha(est);
	}
	else if (strcmp(linha,"poss\n") == 0){
		COORDENADA c[8];
		int n = movs(est,c);
		for(int i = 0; i < n;i++) {showCOORD(c[i]);putchar(' ');}
		putchar('\n'); 
	}
	else if (sscanf(linha,"ler %s",cam) == 1){
		if (read(cam,est)) printf("\nFicheiro inv%clido...\n\n",160);//160 = á em ASCII
		else desenha(est);
	}
	else if (strcmp(linha,"movs\n") == 0) hist(est,stdout);
	else if (sscanf(linha,"gr %s",cam) == 1){
		save(cam,est);
		printf("\nO teu jogo foi salvo\n\n");
	}
	else if (sscanf(linha,"pos %d",&i) == 1) {
		jogAnt(i,est);
		desenha(est);
	}
	else if (strcmp(linha,"bot\n") == 0){ 
		showCOORD(bot(est));
		putchar('\n');
	}
	else if (strcmp(linha,"jog\n") == 0) {jogar(est,jog(est));desenha(est);}
	else if (linha[0] == 'Q') return 0;
	else printf("\nComando Inv%clido!\n\n",160);//160 = á em ASCII
	return 1;
}