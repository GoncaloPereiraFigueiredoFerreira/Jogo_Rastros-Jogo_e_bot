#include "bot.h"


int main (int argc, char *argv[] ){
	if (argc == 3){
		ESTADO *est = malloc (sizeof(ESTADO));
		printf("%s\n%s\n",argv[1],argv[2]);
		if (read (argv[1],est)) printf("Ficheiro não reconhecido\n");
		else { 
			atualizaEstado(est,bot(est));
			save(argv[2],est);}
	}
	else printf ("Erro na chamada da função");

	return 0;
}