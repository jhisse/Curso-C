#include <stdio.h>

int soma(int numeros[10]) {
    int resultado = 0;

    int i;
    for(i = 0; i < 10; i++) {
        resultado += numeros[i];
    }
    return resultado;
}

int main() {
    int numeros[10] = {1,2,3,4,5,6,7,8,9,0};
    int somatorio = soma(numeros);
    printf("%d", somatorio);
}
