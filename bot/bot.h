#ifndef PL6_4_BOT_H
#define PL6_4_BOT_H

#include "../Logica/funcoes.h"
#define DEPTH 20
#define MSCORE 2

ESTADO* cpEst(ESTADO *est);
int max(int v[],int n,int jog);
int minmax (ESTADO *est,int jog,int depth,int max,int min,int *t);
COORDENADA bot (ESTADO *est);

#endif