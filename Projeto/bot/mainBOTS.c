#include "bot.h"


int main (int argc, char *argv[] ){
	if (argc == 3){
		ESTADO *est = malloc (sizeof(ESTADO));
		if (read (argv[1],est)) printf("Ficheiro não reconhecido\n");
		else { 
			jogar(est,bot(est));
			save(argv[2],est);}
	}
	else printf ("Erro na chamada da função");

	return 0;
}