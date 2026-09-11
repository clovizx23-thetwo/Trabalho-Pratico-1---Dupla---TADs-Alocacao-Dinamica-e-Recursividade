#include "montyhall.h"
#include <stdio.h>
#include <time.h>

int main(){
    int n; //numero de eventos
    int acertos = 0;
    int s; //semente aleatoria

    printf("Insira o número de eventos a serem executados: ");
    scanf("%d", &n);
    printf("Insire a semente a ser utilizada: ");
    scanf("%d", &s);

    for(int i = 0; i < n; i++){
        Montyhall *evento = criarEventoMontyHall(s);
        escolhaInicialEventoMontyHall(evento, s);
        int portaRevelada = revelaPortaEventoMontyHall(evento);
        trocaPortaEventoMontyHall(evento, portaRevelada);
        if(verificaVitoriaEventoMontyHall(evento)) {
            printf("Acertou!\n");
            acertos++;
        } else
            printf("Errou");
        destroiEventoMontyHall(evento);
    }

    float porcentagemAcertos = (acertos / n) * 100.0;

    return 0;
}