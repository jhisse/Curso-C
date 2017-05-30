#include <stdio.h>

int main() {
    printf("Multiplicação de dois números inteiros\n\n");

    int x;

    printf("Digite seu primeiro número inteiro: ");
    scanf("%d", &x);

    int y;

    printf("Digite seu segundo número inteiro: ");
    scanf("%d", &y);

    int resultado = x*y;

    printf("\nA multiplicação de %d por %d tem como resultado %d", x, y, resultado);
}
