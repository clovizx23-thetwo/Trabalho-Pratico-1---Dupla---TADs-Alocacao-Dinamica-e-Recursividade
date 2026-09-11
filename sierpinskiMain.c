#include "TapetedeSierpinski.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int p, n;
    printf("Digite o nuemero para ser o expoente da matriz: ");
    scanf("%d", &p);
    //calculando os laodos da matriz
    
    int n = pow(3, p);
    printf("\nO valor de n eh:\n", n);

    for(int i = 0; i < n; i++){
        int *matN = criarMatriz(n);
        if(matN != NULL){
            tapeteSierpinski(int i, int j, int size, int M);
        }
    }

    return 0;
}