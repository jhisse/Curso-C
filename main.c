#include <stdio.h>

int main() {

    // imprime o cabeçalho do jogo
    printf("*******************************************\n");
    printf("* Bem vindo ao nosso jogo da adivinhação! *\n");
    printf("*******************************************\n");

    int numero_secreto = 42;

    int chute;

    printf("Qual o seu chute? ");
    scanf("%d", &chute);
    printf("Seu chute foi %d.", chute);


}
