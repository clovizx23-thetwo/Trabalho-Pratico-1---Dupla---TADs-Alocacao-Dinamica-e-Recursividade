#ifndef MONTYHALL_H
#define MONTYHALL_H

#include <stdbool.h>

typedef struct eventoMontyhall{
    bool portas[3]; //true na correta; false nas erradas
    int escolhaJogador;
} Montyhall;

Montyhall criarEventoMontyHall(int s);

Montyhall destroiEventoMontyHall(Montyhall);

Montyhall revelaPortaEventoMontyHall(Montyhall);

Montyhall trocaPortaEventoMontyHall(Montyhall);

Montyhall verificaVitoriaEventoMontyHall(Montyhall);

#endif