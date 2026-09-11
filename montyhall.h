#IFNDEF MONTYHALL_H
#DEFINE MONTYHALL_H

#include <stdbool.h>

typedef struct () {
    bool portas[3] //true na correta; false nas erradas
    int escolhaJogador;
} Montyhall;

Montyhall criarEventoMontyHall();

Montyhall destroiEventoMontyHall(Montyhall);

Montyhall revelaPortaEventoMontyHall(Montyhall);

Montyhall trocaPortaEventoMontyHall(Montyhall);

Montyhall verificaVitoriaEventoMontyHall(Montyhall);

#ENDIF