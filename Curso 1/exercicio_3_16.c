#include <stdio.h>

int main() {
    printf("Tabuado do número escolhido\n\n");

    printf("Insira o número desejado: ");
    int numero;
    scanf("%d", &numero);

    int i;
    for (i=1;i<=10;i++){
        int resultado = numero * i;
        printf("%d x %d = %d\n", numero, i, resultado);
    };
}
