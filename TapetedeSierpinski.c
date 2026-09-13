#include "TapetedeSierpinski.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tapeteSierpinski(int i, int j, int size, int **M){
    if(size == 1){
        M[i][j] = 1;
        return;
    }

    int suBloco = size / 3;

    for(int lin = i + suBloco; lin < i + 2*suBloco; lin++){
        for(int col = j + suBloco; col < j + 2*suBloco; col++){
            M[lin][col] = 0;
        }
    }

    tapeteSierpinski(i, j, suBloco, M);//
    tapeteSierpinski(i, j + 2*suBloco, suBloco, M);//
    tapeteSierpinski(i + suBloco, j, suBloco, M);//
    tapeteSierpinski(i + suBloco, j + 2*suBloco, suBloco, M);//
    tapeteSierpinski(i + 2*suBloco, j, suBloco, M);//
    tapeteSierpinski(i + 2*suBloco, j + suBloco, suBloco, M);//
    tapeteSierpinski(i + 2*suBloco, j + 2*suBloco, suBloco, M);//
}
int **criarMatriz(int n){
    int **tapMat = (int**)malloc(sizeof(int*)*n);
    for(int j = 0; j < n; j++){
        tapMat[j] = (int*)malloc(sizeof(int)*n);
        for(int k = 0; k < n; k++){
            tapMat[j][k] = 1;
        }
    }
    return tapMat;
}
void liberaSierpinski(int **matriz, int n){
    for(int i = 0; i < n; i++){
        free(matriz[i]);
    }
    free(matriz);
}