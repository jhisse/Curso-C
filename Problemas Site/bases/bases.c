/*
* Imprimindo em diversas bases
*/

#include <stdio.h>

int main() {
    int numero;
    do{
        scanf("%d", &numero);
        printf("%05d %05o %05x\n", numero, numero, numero);
    } while (getchar() != 99);
}
