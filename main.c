//26.1.4147
//26.1.4048

#include "montyhall.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){    
    printf("\n========TRABALHO PRÁTICO 01========\n");
    printf("\nAlunos///////////////|");
    printf("\nClovis Loyola Soares |");
    printf("\nValter Simão         |");
    printf("\n/////////////////////|\n");

    int escolha;
    
    printf("\n1 - PARADOXO DE MONTY HALL");
    printf("\n2 - TAPETE DE SIERSPINSKI\n");

    do{
        printf("\nSUA ESCOLHA: ");
        scanf("%d", &escolha);
        if(escolha != 1 && escolha != 2){
            printf("\nOPCAO ERRADA\n");
        }
    }while(escolha != 1 && escolha != 2);

    switch(escolha){
        case 1:
            mainMontyhall();
            break;
        
        case 2:
            mainSierpinski();
            break;
    }

    return 0;
}