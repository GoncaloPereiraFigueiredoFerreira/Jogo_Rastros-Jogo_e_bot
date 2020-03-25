#ifndef PL6_4_IMPRIMIR_H
#define PL6_4_IMPRIMIR_H

#include "../Logica/funcoes.h"

#define BUF_SIZE 1024

void showCOORD (COORDENADA c);
void prompt (ESTADO *est);
void desenhal();
void desenha(ESTADO *est);
int escolheVencedor(ESTADO *est);
int interpretador(ESTADO *est);
void hist(ESTADO *est,FILE *f);
void save(char cam[],ESTADO *est);


#endif