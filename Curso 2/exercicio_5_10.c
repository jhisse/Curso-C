#include <stdio.h>

void soma(int* num, int a, int b) {
    (*num) = (a + b);
    printf("Função soma: %d na memória %d\n", (*num), &(*num));
}

void main() {
    int num = 0;
    int c = 1;
    int d =2;
    printf("Função main: %d na memória %d\n", num, &num);
    soma(&num, c, d);
    printf("Função main: %d na memória %d\n", num, &num);
}
