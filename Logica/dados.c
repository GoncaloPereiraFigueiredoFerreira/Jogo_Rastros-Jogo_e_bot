//Camada de Dados

typedef enum {VAZIO, BRANCA, PRETA} CASA;

typedef struct {
int x;
int y;
} COORDENADA;


typedef COORDENADA JOGADAS[64];

typedef struct {
CASA tab[8][8];
COORDENADA pos;
JOGADAS jogadas;
int num_jogadas;
int jogador_atual;
} ESTADO;

