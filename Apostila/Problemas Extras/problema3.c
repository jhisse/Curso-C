#include <stdio.h>
#include <string.h>

int main() {
    char string_cpf[11];
    int cpf[11];

    printf("Digite o cpf que deseja verificar: ");
    scanf(" %s", &cpf);

    int i;
    for(i = 0; i <= 11; i++) {
        cpf[i] = string_cpf[i];
        printf("%d\n",cpf[i]);
    }
}
