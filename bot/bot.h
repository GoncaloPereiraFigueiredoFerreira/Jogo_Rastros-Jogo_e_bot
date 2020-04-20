#ifndef PL6_4_BOT_H
#define PL6_4_BOT_H

#include "../Logica/funcoes.h"
#define DEPTH 20
#define MSCORE 100000

ESTADO* cpEst(ESTADO *est);
int dist(COORDENADA c,COORDENADA c1);
int value(ESTADO *est,int jog);
int minmax (ESTADO *est,int jog,int depth,int max,int min,int *t);
COORDENADA bot (ESTADO *est);

#endif