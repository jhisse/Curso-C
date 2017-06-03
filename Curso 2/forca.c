#include <stdio.h>
#include <string.h>

char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

void abertura() {
    printf("***********************\n");
    printf("*    Jogo da Forca    *\n");
    printf("***********************\n\n");
}

void chuta() {
    char chute;
    scanf(" %c", &chute);
    chutes[tentativas] = chute;
    tentativas++;
}

int jachutou(char letra) {
    for(int j = 0; j < tentativas; j++) {
        if(chutes[j] == letra){
            return 1;
        }
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
    sprintf(palavrasecreta, "MELANCIA");
}

int main() {
    escolhepalavra();
    abertura();

    int acertou = 0;
    int enforcou = 0;

    do{
        desenhaforca();
        chuta();
    } while(!acertou && !enforcou);
}
