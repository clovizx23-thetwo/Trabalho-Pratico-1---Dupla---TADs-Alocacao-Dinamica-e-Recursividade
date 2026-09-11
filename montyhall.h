#ifndef MONTYHALL_H
#define MONTYHALL_H

#include <stdbool.h>

typedef struct eventoMontyhall{
    bool portas[3]; //true na correta; false nas erradas
    int escolhaJogador;
} Montyhall;

Montyhall * criarEventoMontyHall(int s);

void escolhaInicialEventoMontyHall(Montyhall, int s);

Montyhall * destroiEventoMontyHall(Montyhall);

int revelaPortaEventoMontyHall(Montyhall);

trocaPortaEventoMontyHall(Montyhall, int portaRevelada);

bool verificaVitoriaEventoMontyHall(Montyhall);

#endif