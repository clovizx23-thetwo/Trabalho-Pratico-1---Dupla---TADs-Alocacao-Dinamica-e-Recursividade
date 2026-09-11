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

Montyhall destroiEventoMontyHall(Montyhall);

Montyhall revelaPortaEventoMontyHall(Montyhall);

Montyhall trocaPortaEventoMontyHall(Montyhall);

Montyhall verificaVitoriaEventoMontyHall(Montyhall);
