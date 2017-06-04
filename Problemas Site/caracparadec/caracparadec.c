#include <stdio.h>

int main() {
    char caractere;
    while((caractere = getchar()) != EOF){
        printf("%c = %d\n", caractere, caractere);
        getchar();
    }
    return 0;
}
