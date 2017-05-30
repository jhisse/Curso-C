#include <stdio.h>

int main() {

    // imprime o cabeçalho do jogo
    printf("*******************************************\n");
    printf("* Bem vindo ao nosso jogo da adivinhação! *\n");
    printf("*******************************************\n");

    int numero_secreto = 42;

    int chute;

    int tentativa;

    for (tentativa = 1; tentativa <= 3; tentativa++) {
        printf("Tentativa %d de 3\n", tentativa);
        printf("Qual o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d.\n", chute);

        int acertou = (chute == numero_secreto);

        if (acertou) {
            printf("Parabéns! Você acertou!\n");
        } else {

            int maior = (chute > numero_secreto);

            if (maior) {
                printf("Você errou! O número que você chutou é maior que o número secreto.\n");
            } else {
                printf("Você errou! O número que você chutou é menor que o número secreto.\n");
            }; // end if

        }; // end if

    }; // end for

    printf("Fim de jogo!");
}
