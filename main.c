#include <stdio.h> 
#include <string.h>
#define BUF_SIZE 1024
#include "interface/interface.h"



int main() {
	ESTADO* est =inicia();
	desenha(est);
	while (interpretador(est));
	return 0;
}
/*Ideias:
Regras de GameOver;
Sans;
Por tabuleiro a meio do ecran;
Limpar a consola;
Interface Melhor;

*/