#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void liberamapa(MAPA* m) {
    int i;
    for(i = 0; i < m->linhas; i++) {
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void alocamapa(MAPA* m) {
    m->matriz = malloc(sizeof(char*) * m->linhas);
    int i;
    for(i = 0; i < m->linhas; i++) {
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
    }
}

void lemapa(MAPA* m) {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if(f == 0){
        printf("Desculpe, não foi possível abrir o mapa.");
        exit(1);
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
    alocamapa(m);
    int i;
    for(i = 0; i < m->linhas; i++){
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}

void imprimemapa(MAPA* m) {
    int i;
    for(i = 0; i < m->linhas; i++){
        printf("%s\n", m->matriz[i]);
    }
}

void encontramapa(MAPA* m, POSICAO* p, char c) {
  int i;
  for(i = 0; i < m->linhas; i++) {
      int j;
      for(j = 0; j < m->colunas; j++) {
          if(m->matriz[i][j] == c) {
              p->x = i;
              p->y = j;
              break;
          }
      }
  }
}

void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino) {
	
  char personagem = m->matriz[xorigem][yorigem];
  
  m->matriz[xdestino][ydestino] = personagem;
  m->matriz[xorigem][yorigem] = '.';

}