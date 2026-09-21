#include "montyhall.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
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
        }
        destroiEventoMontyHall(evento);
    }

    float porcentagemAcertos = ((float)acertos / n) * 100.0;

    printf("\nQuantidade de vitórias: %.2f%%", porcentagemAcertos);
    printf("\nQuantidade de derrotas: %.2f%%\n", (100.0 - porcentagemAcertos));

    printf("\n\n========TAPETE DE SIERPINSKI========");

    int p, ns;

    printf("\n\nDigite o numero para ser o expoente da matriz: ");
    scanf("%d", &p);
    //calculando os laodos da matriz
    ns = pow(3, p);
    printf("\nO valor de n eh: %d\n", ns);

    int **matN = criarMatriz(ns);

    if(matN != NULL){
        
        tapeteSierpinski(0, 0, ns, matN);

        for(int line2 = 0; line2 < ns; line2++){
            for(int col2 = 0; col2 < ns; col2++){
                printf("%d", matN[line2][col2]);
                if(col2 < ns-1)
                    printf(" ");
            }
            printf("\n");
        }
        printf("\n");

        liberaSierpinski(matN, ns);
    }
    return 0;
}