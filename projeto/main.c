#include "interface.h"
#include <stdlib.h>

/**
\brief Main
*/
int main() {
	ESTADO *est = (ESTADO *) malloc(sizeof(ESTADO));
	inicia(est);
	limpaArr(est,0);
	desenhoInicial ();
	desenha(est);
	while (interpretador(est));
	free(est);
	system ("pause");
	return 0;
}
