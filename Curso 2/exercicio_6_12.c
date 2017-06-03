#include <stdio.h>

int main() {
    FILE* f;
    f = fopen("teste.txt", "r");
    if(f == 0){
        printf("Erro na leitura.");
        exit(1);
    }
    char palavra[20];
    fscanf(f, "%s", palavra);
    printf("%s", palavra);
}
