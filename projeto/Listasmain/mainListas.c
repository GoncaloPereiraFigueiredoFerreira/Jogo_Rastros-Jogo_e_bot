#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listasligadas.h"


#define BUF_SIZE 1024

int main() {
  LISTA L = criarL(); // Criar uma lista vazia
  char linha[BUF_SIZE];
    
  printf("Insira várias linhas, acabando com CTRL-D:\n");

  // control-D é a tecla CTRL e a tecla D ao mesmo tempo
  // Em windows é capaz de ser CTRL-Z
    while(fgets(linha, BUF_SIZE, stdin) != 0) {
        // A função strdup cria uma cópia da string que foi lida
        // Insere uma cópia da linha lida na cabeça da lista
        L = insereH(L, strdup(linha));
    }

  printf("\n==============================\n");
  printf(  "=          PERCURSO          =\n");
  printf(  "==============================\n\n");
    // percorre sem remover os elementos da lista
    for(LISTA T = L; !vazia(T); T = proximo(T)) {
        // Vai buscar a cabeça da lista
        // Passa do tipo genérico void * para char *
        char *str = (char *) devolveH(T);
        printf("%s", str);
    }
    
  printf("\n==============================\n");
  printf(  "=           REMOCAO          =\n");
  printf(  "==============================\n\n");
    // percorre e vai removendo a cabeça
    while(!vazia(L)) {
        char *str = (char *) devolveH(L);
        L = removeH(L);
        printf("%s", str);
        free(str);
    }
  return 0;
}