#include "montyhall.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tapeteSierpinski(int i, int j, int size, int **M){
    if(size == 1){
        M[i][j] = 1;
        return;
    }

    //cada quadradinho tem tamanho [size / 3], pq são 9 quadradinhos o tapete total
    int quadradoInterno = size / 3;

    for(int l = i + quadradoInterno;)

    tapeteSierpinski(i, j, quadradoInterno, M); //quadrado superior esquerdo
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