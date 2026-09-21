//26.1.4147
//26.1.4048

#include "montyhall.h"
#include <stdlib.h>
#include <stdio.h>

Montyhall * criarEventoMontyHall() {
    Montyhall * evento = (Montyhall*) malloc(sizeof(evento));
    if(evento != NULL) {
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

void escolhaInicialEventoMontyHall(Montyhall * evento) {
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
            evento->escolhaJogador = i;//nova escolha do jogador "trocada".
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

void mainMontyhall() {
    int n; //numero de eventos
    int acertos = 0;
    int s; //semente aleatoria
    printf("\n========MONTHYHALL========\n");
    printf("\nInsira o número de eventos a serem executados: ");
    scanf("%d", &n);
    printf("Insire a semente a ser utilizada: ");
    scanf("%d", &s);
    srand(s);

    for(int i = 0; i < n; i++){
        Montyhall *evento = criarEventoMontyHall();
        printf("\n%d|%d|%d\n", evento->portas[0] ? 1 : 0, evento->portas[1] ? 1 : 0, evento->portas[2] ? 1 : 0);//teste
        escolhaInicialEventoMontyHall(evento);
        int portaRevelada = revelaPortaEventoMontyHall(evento);
        trocaPortaEventoMontyHall(evento, portaRevelada);
        if(verificaVitoriaEventoMontyHall(evento)) {
            printf("->Acertou!\n\n");
            acertos++;
        } else
            printf("->Errou!\n\n");
        destroiEventoMontyHall(evento);
    }

    float porcentagemAcertos = ((float)acertos / n) * 100.0;

    printf("\nQuantidade de vitórias: %.2f%%", porcentagemAcertos);
    printf("\nQuantidade de derrotas: %.2f%%\n", (100.0 - porcentagemAcertos));
}