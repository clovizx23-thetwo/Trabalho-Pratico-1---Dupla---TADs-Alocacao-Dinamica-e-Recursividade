#ifndef MONTYHALL_H
#define MONTYHALL_H

#include <stdbool.h>

typedef struct eventoMontyhall{
    bool portas[3]; //true na correta; false nas erradas
    int escolhaJogador;
} Montyhall;

Montyhall criarEventoMontyHall(int s);

void escolhaInicialEventoMontyHall(Montyhall, int s);

Montyhall destroiEventoMontyHall(Montyhall, int s);

int revelaPortaEventoMontyHall(Montyhall, int s);

trocaPortaEventoMontyHall(Montyhall, int portaRevelada, int s);

bool verificaVitoriaEventoMontyHall(Montyhall, int s);

#endif