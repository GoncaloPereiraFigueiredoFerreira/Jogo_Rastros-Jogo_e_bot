#include "interface/interface.h"
#include <stdlib.h>
int main() {
	ESTADO *est = (ESTADO *) malloc(sizeof(ESTADO));
	inicia(est);
	limpaArr(est,0);
	desenhoInicial ();
	desenha(est);
	while (interpretador(est));
	system ("pause");
	return 0;
}
/*Ideias:
Regras de GameOver;
Sans;
Por tabuleiro a meio do ecran;
Limpar a consola;
Interface Melhor;

*/