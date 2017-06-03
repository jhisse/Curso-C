#include <stdio.h>

int parimpar(int n) {
    int par = (n % 2 == 0);

    if(par) {
        return 1;
    }
    return 0;
}

void main() {
    int numero;
    printf("Qual numero deseja verificar se é par ou ímpar? ");
    scanf("%d", &numero);

    int par = parimpar(numero);

    if(par) {
        printf("Seu número é par.");
    } else {
        printf("Seu número é ímpar.");
    }
}
