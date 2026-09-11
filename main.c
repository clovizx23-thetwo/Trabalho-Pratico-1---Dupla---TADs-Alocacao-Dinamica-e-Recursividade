#include "montyhall.h"
#include <stdio.h>
#include <time.h>

int main(){
    int n; //numero de eventos
    int acertos = 0;
    int s; //semente aleatoria

    printf("Insira o número de eventos e a semente a ser utilizada: ");
    scanf("%d %d", &n, &s);

    for(int i = 0; i < n; i++){
        Montyhall *evento = criarEventoMontyHall(s);
        escolhaInicialEventoMontyHall(evento, s);
        int portaRevelada = revelaPortaEventoMontyHall(evento);
        trocaPortaEventoMontyHall(evento, portaRevelada);
        if(verificaVitoriaEventoMontyHall(evento)) {
            acertos++;
        }
        evento = destroiEventoMontyHall(evento);
    }

    float porcentagemAcertos = (acertos / n) * 100.0;

    return 0;
}