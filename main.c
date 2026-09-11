#include "montyhall.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n; //numero de eventos
    int acertos = 0;
    int s; //semente aleatoria

    printf("Insira o número de eventos a serem executados: ");
    scanf("%d", &n);
    printf("Insire a semente a ser utilizada: ");
    scanf("%d", &s);
    srand(s);

    for(int i = 0; i < n; i++){
        Montyhall *evento = criarEventoMontyHall();
        printf("\n%d|%d|%d\n", evento->portas[0] ? 1 : 0, evento->portas[1] ? 1 : 0, evento->portas[2] ? 1 : 0);//teste
        escolhaInicialEventoMontyHall(evento);
        int portaRevelada = revelaPortaEventoMontyHall(evento);
        trocaPortaEventoMontyHall(evento, portaRevelada);
        if(verificaVitoriaEventoMontyHall(evento)) {
            printf("Acertou!\n\n");
            acertos++;
        } else
            printf("Errou\n\n");
        destroiEventoMontyHall(evento);

    }

    float porcentagemAcertos = (acertos / n) * 100.0;

    return 0;
}