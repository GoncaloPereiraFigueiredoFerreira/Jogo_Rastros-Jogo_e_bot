#include "interface.h"

void hist(ESTADO *est,FILE *f){
	int i;
	COORDENADA c;
	for(i = 0;i<(est->num_jogadas);i++){
		c = est->jogadas[i];
		if (!(i%2)) fprintf(f,"\n%02d:",(i/2)+1);
		fprintf(f," %c%d",c.x+'a',8-c.y);
	}
	fputc('\n',f);
}

void save(char cam[],ESTADO *est){
	FILE *f;
	int x,y;
	//COORDENADA c;
	f = fopen(cam,"w");
	for (x = 0;x<8;x++){
		for (y = 0;y<8;y++){
			if (x == 7 && y == 0 && est->tab[y][x] != '*') fputc('1',f);
			else if (x == 0 && y == 7 && est->tab[y][x] != '*') fputc('2',f); 
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
	int c = 0;
	if (f != NULL){
		for (i = 0;i<8;i++){
			if (fgets(cam,MAX,f)){
			for(i1 = 0;cam[i1]!='\n' &&cam[i1]!='\0' ;i1++){
				if (cam[i1] == '1' || cam[i1] == '2') est->tab[i][i1] = '.'; // atençao a isto em caso de mudar vazia
				else { est->tab[i1][i] = cam [i1];
					if (cam[i1] == '*') {
						est->pos.x = i1;
						est->pos.y = i;
					}
				}
			}
		}
		else return 1;
	}

		while (fgets(cam,BUF_SIZE,f) != NULL){
			for(i1 = 0;cam[i1]!='\0';i1++){
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
