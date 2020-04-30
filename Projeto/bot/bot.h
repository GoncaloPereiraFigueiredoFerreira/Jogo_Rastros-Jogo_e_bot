#ifndef PL6_4_BOT_H
#define PL6_4_BOT_H

#include "../interface/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Logica/funcoes.h"
#define DEPTH 20
#define MSCORE 100000

ESTADO* cpEst(ESTADO *est);
int value(ESTADO *est,int jog);
int minmax (ESTADO *est,int jog,int depth,int max,int min,int *t);
int fill(ESTADO *est1,int tab[8][8]);
COORDENADA bot (ESTADO *est);

#endif