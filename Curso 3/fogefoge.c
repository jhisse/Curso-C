#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

Mapa m;

void liberamapa() {
    int i;
    for(i = 0; i < m.linhas; i++) {
        free(m.matriz[i]);
    }
    free(m.matriz);
}

void alocamapa() {
    m.matriz = malloc(sizeof(char*) * m.linhas);
    int i;
    for(i = 0; i < m.linhas; i++) {
        m.matriz[i] = malloc(sizeof(char) * (m.colunas + 1));
    }
}

void lemapa() {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if(f == 0){
        printf("Desculpe, não foi possível abrir o mapa.");
        exit(1);
    }

    fscanf(f, "%d %d", &(m.linhas), &(m.colunas));
    alocamapa();
    int i;
    for(i = 0; i < m.linhas; i++){
        fscanf(f, "%s", m.matriz[i]);
    }
    fclose(f);
}

void imprimemapa() {
    int i;
    for(i = 0; i < m.linhas; i++){
        printf("%s\n", m.matriz[i]);
    }
}

int acabou(){
    return 0;
}

void move(char direcao) {
    int x;
    int y;
    int i;
    for(i = 0; i < m.linhas; i++) {
        int j;
        for(j = 0; j < m.colunas; j++) {
            if(m.matriz[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
        }
    }

    switch(direcao){
        case 'a':
            m.matriz[x][y-1] = '@';
            break;
        case 'w':
            m.matriz[x-1][y] = '@';
            break;
        case 's':
            m.matriz[x+1][y] = '@';
            break;
        case 'd':
            m.matriz[x][y+1] = '@';
            break;
    }

    m.matriz[x][y] = '.';
}

int main() {
    lemapa();

    do{
        imprimemapa();

        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while(!acabou());

    liberamapa();
}
