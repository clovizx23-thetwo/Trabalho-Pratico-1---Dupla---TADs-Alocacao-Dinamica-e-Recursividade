#include "montyhall.h"
#include <stdlib.h>
#include <stdio.h>

Montyhall * criarEventoMontyHall(int s) {
    Montyhall * evento = (Montyhall*) malloc(sizeof(evento));
    if(!evento) {
        srand(s);
        int in = rand() % 3;
        for (int i = 0; i < 3; i++)
            evento->portas[i] = (i == in ? true : false);

        return evento;
    } else {
        printf("Erro ao alocar eventoMontyhall\n");
        return NULL;
    }

}

Montyhall * destroiEventoMontyHall(Montyhall * evento) {
    free(evento);
    return evento;
}

void escolhaInicialEventoMontyHall(Montyhall evento, int s) {
    srand(s);
    int escolha = rand() % 3;
    printf("Escolha da máquina: Porta 0%d\n", escolha+1);
    evento.escolhaJogador = escolha;
}


int revelaPortaEventoMontyHall(Montyhall);

trocaPortaEventoMontyHall(Montyhall);

bool verificaVitoriaEventoMontyHall(Montyhall);