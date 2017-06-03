#include <stdio.h>

int potencia(int* resultado, int base, int expoente){
    int i;
    for(i = 1; i <= expoente; i++) {
        *resultado *= base;
    }
}

int main() {
    int resultado = 1;
    potencia(&resultado, 2, 2);
    printf("%d", resultado);
}
