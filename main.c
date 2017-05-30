#include <stdio.h>

int main() {

    // imprime o cabeçalho do jogo
    printf("*******************************************\n");
    printf("* Bem vindo ao nosso jogo da adivinhação! *\n");
    printf("*******************************************\n");

    int numero_secreto = 42;

    int chute;

    int tentativa = 1;

    while (1) {
        printf("Tentativa %d\n", tentativa);
        printf("Qual o seu chute? ");

        scanf("%d", &chute);

        printf("Seu chute foi %d.\n", chute);

        if (chute < 0) {
            printf("Você não pode chutar números negativos.\n");

            continue; // pula para a próxima iteração do while
        };

        int acertou = (chute == numero_secreto);

        int maior = (chute > numero_secreto);

        if (acertou) {
            printf("Parabéns! Você acertou!\n");

            break; // para o laço while
        } else if (maior) {
            printf("Você errou! O número que você chutou é maior que o número secreto.\n");
        } else {
            printf("Você errou! O número que você chutou é menor que o número secreto.\n");
        };

        tentativa++;

    }; // end while

    printf("Fim de jogo!\n");
    printf("Você acertou em %d tentativas.\n", tentativa);
}
