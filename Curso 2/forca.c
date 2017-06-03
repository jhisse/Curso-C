#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>

char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

void abertura() {
    printf("***********************\n");
    printf("*    Jogo da Forca    *\n");
    printf("***********************\n\n");
}

void chuta() {
    char chute;
    scanf(" %c", &chute);
    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou(char letra) {
    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) return 1;
    }
    return 0;
}

void desenhaforca() {
    int tamanho_da_palavra = strlen(palavrasecreta);

    for(int i = 0; i < tamanho_da_palavra; i++) {

        int achou = jachutou(palavrasecreta[i]);

        if(achou) {
            printf("%c ",palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhepalavra() {
    FILE* f;

    f = fopen("palavras.txt", "r");

    if(f == 0){
        printf("Desculpe. Banco de dados não disponível.");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() %qtddepalavras;

    int i;
    for(i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

int enforcou() {

    int erros = 0;

    int i;
    for(i = 0; i < chutesdados; i++) {
        int existe = 0;

        int j;
        for(j = 0; j < strlen(palavrasecreta); j++) {
            if(chutes[i] == palavrasecreta[j]) {
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros >= 5;
}

int acertou() {
    int i;
    for(i=0; i < strlen(palavrasecreta); i++) {
        if(!jachutou(palavrasecreta[i])) return 0;
    }
    return 1;
}

int main() {
    escolhepalavra();
    abertura();
    do{
        desenhaforca();
        chuta();
    } while(!acertou() && !enforcou());
}
