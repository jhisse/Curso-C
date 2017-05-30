#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // imprime o cabeçalho do jogo
    printf("*******************************************\n");
    printf("* Bem vindo ao nosso jogo da adivinhação! *\n");
    printf("*******************************************\n");

    int segundos = time(0);
    srand(segundos);

    int numero_secreto = rand() % 100;

    int chute;

    int tentativa = 1;

    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int maximo_de_tentativas;

    switch (nivel) {
        case 1:
            maximo_de_tentativas = 20;
            break;
        case 2:
            maximo_de_tentativas = 15;
            break;
        default:
            maximo_de_tentativas = 6;
            break;
    };

    for (tentativa; tentativa <= maximo_de_tentativas; tentativa++) {
        printf("Tentativa %d de %d\n", tentativa, maximo_de_tentativas);
        printf("Qual o seu chute? ");

        scanf("%d", &chute);

        printf("Seu chute foi %d.\n", chute);

        if (chute < 0) {
            printf("Você não pode chutar números negativos.\n");

            tentativa--;

            continue; // pula para a próxima iteração do while
        };

        int acertou = (chute == numero_secreto);

        int maior = (chute > numero_secreto);

        if (acertou) {
            break; // para o laço
        } else if (maior) {
            printf("Você errou! O número que você chutou é maior que o número secreto.\n");
        } else {
            printf("Você errou! O número que você chutou é menor que o número secreto.\n");
        };

        double pontosperdidos = abs(chute - numero_secreto) / (double)2;
        pontos -= pontosperdidos;

    }; // end for

    printf("Fim de jogo!\n");

    if (acertou) {
        printf("Você ganhou! Parabéns!");
        printf("Você acertou em %d tentativas.\n", tentativa);
        printf("Total de pontos : %.1f\n", pontos);
    } else {
        printf("Você perdeu. Tente denovo.");
    };
}
