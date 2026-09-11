#include "montyhall.h"
#include <stdlib.h>

Montyhall criarEventoMontyHall(int s) {
    Montyhall evento;
    srand(s);
    int in = rand() % 3;
    for (int i = 0; i < 3; i++)
        evento.portas[i] = (i == in ? true : false);

    return evento;

}

void escolhaInicialEventoMontyHall(Montyhall);

Montyhall destroiEventoMontyHall(Montyhall);

int revelaPortaEventoMontyHall(Montyhall);

trocaPortaEventoMontyHall(Montyhall);

bool verificaVitoriaEventoMontyHall(Montyhall);