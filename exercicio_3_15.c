#include <stdio.h>

int main() {
    printf("Calculadora de dois números\n\n");

    printf("Qual operação vc deseja fazer?  (1 = soma, 2 = subtração, 3 = divisão, 4 = multiplicação) ");
    int opcao;
    scanf("%d", &opcao);

    printf("Qual será o valor do primeiro número? ");
    int x;
    scanf("%d", &x);

    printf("Qual será o valor do segundo número? ");
    int y;
    scanf("%d", &y);

    int resultado;

    if (opcao == 1) {
        resultado = x + y;
    } else if (opcao = 2) {
        resultado = x - y;
    } else if (opcao = 3) {
        resultado = x / y;
    } else {
        resultado = x * y;
    };
    printf("Resultado: %d", resultado);
}
