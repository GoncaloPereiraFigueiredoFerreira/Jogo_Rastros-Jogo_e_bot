//Camada de Dados

typedef enum {VAZIO = '.', BRANCA = '*', PRETA = '#'} CASA;

typedef struct {
int x; // Colunas
int y; // Linhas
} COORDENADA;

// Array com todas as posições ocupadas por peças pretas
typedef COORDENADA JOGADAS[64];

typedef struct {
CASA tab[8][8]; // Estado Do Tabuleiro
COORDENADA pos; // Posicção da Peça Branca
JOGADAS jogadas; // Lista de Jogadas ja Feitas || Peças Pretas 
int num_jogadas;  // Número de Jogadas Realizadas até agora
int jogador_atual; // Qual o Jogador a Jogar
} ESTADO;

ESTADO* inicia();
int jogPoss (ESTADO *est,COORDENADA mvs[8]);
int check (ESTADO *est,COORDENADA c);
int verificaFim (ESTADO *est);