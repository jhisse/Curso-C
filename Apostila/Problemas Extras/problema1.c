#include <stdio.h>

int main() {
    float distancia = 1000; //metros
    int pausa = 5; //minutos

    int tempo_total = 0;

    do {
        distancia = distancia / (float)2;

        tempo_total = tempo_total + pausa;

    } while(distancia > 0.001);

    printf("Tempo total: %d minutos\n", tempo_total);
}
