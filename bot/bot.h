#ifndef PL6_4_BOT_H
#define PL6_4_BOT_H

#include "../Logica/funcoes.h"
#define DEPTH 10000

ESTADO* cpEst(ESTADO *est);
int max(int v[],int n,int jog);
int minmax(ESTADO *est,int jog,int depth);
COORDENADA bot (ESTADO *est);

#endif