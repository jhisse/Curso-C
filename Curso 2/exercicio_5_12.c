#include <stdio.h>

int soma(int* numeros, int tamanho) {
    int resultado = 0;

    int i;
    for(i = 0; i < tamanho; i++) {
        resultado += numeros[i];
    }
    return resultado;
}

int main() {
    int numeros[10] = {1,2,3,4,5,6,7,8,9,0};
    int somatorio = soma(numeros, 10);
    printf("%d", somatorio);
}
