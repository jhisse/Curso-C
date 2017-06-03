#include <stdio.h>

int potencia(int base, int expoente){
    int resultado = 1;

    int i;
    for(i = 1; i <= expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

int main() {
    int resultado = potencia(3,2);
    printf("%d", resultado);
}
