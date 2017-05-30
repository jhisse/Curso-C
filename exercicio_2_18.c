#include <stdio.h>

int main() {
    int i = 1;
    int soma;
    while (i <= 100) {
        soma += i;
        i++;
    };
    printf("%d", soma);
}
