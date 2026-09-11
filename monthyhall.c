#include "montyhall.h"
#include <stdlib.h>
#include <stdio.h>

Montyhall * criarEventoMontyHall(int s) {
    Montyhall * evento = (Montyhall*) malloc(sizeof(evento));
    if(evento != NULL) {
        srand(s);
        int in = rand() % 3;
        for (int i = 0; i < 3; i++) //Passa pelo laço para atribuir os valores falsos tambem
            evento->portas[i] = (i == in ? true : false);

        return evento;
    } else {
        printf("Erro ao alocar eventoMontyhall\n");
        return NULL;
    }

}

void destroiEventoMontyHall(Montyhall * evento) {
    free(evento);
}

void escolhaInicialEventoMontyHall(Montyhall * evento, int s) {
    srand(s);
    int escolha = rand() % 3;
    printf("Escolha da máquina: Porta 0%d\n", escolha+1);
    evento->escolhaJogador = escolha;
}

int revelaPortaEventoMontyHall(Montyhall * evento) {
    for (int i = 0; i < 3; i++) {
        if(i != evento->escolhaJogador && (!evento->portas[i])) {
            printf("Foi revelado a Porta 0%d e é uma porta incorreta!\n", i+1);
            return i;
        }
    }
    return -1;
}

void trocaPortaEventoMontyHall(Montyhall * evento, int portaRevelada) {
    for (int i = 0; i < 3; i++) {
        if(i != evento->escolhaJogador && i != portaRevelada) {
            printf("A máquina trocou da Porta 0%d para a Porta 0%d!\n",evento->escolhaJogador +1, i+1);
            evento->escolhaJogador = i;
            return;
        }
    }
}

bool verificaVitoriaEventoMontyHall(Montyhall * evento) {
    if(evento->portas[evento->escolhaJogador])
        return true;
    else
        return false;
}