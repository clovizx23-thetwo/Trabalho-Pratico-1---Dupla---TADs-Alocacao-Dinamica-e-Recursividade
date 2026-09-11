#include "TapetedeSierpinski.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int p, n;
    int i, j, size;
    printf("Digite o numero para ser o expoente da matriz: ");
    scanf("%d", &p);
    //calculando os laodos da matriz
    n = pow(3, p);
    printf("\nO valor de n eh: %d\n", n);

    for(int i = 0; i < n; i++){
        int **matN = criarMatriz(n);
        if(matN != NULL){
            tapeteSierpinski(i, j, n, matN);
        }
    }

    return 0;
}