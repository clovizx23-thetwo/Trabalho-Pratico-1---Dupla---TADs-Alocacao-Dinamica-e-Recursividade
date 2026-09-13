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

    int **matN = criarMatriz(n);
    if(matN != NULL){
        matN = tapeteSierpinski(i, j, n, matN);
        
        for(int line = 0; line < n; line++){
            for(int col = 0; col < n; col++)
                printf("%d", matN[line][col]);
                if(line <= col)
                    printf(" ");
            printf("\n");
        }

        liberaSierpinski(matN, n);
    }
    return 0;
}