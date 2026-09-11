#include "TapetedeSierpinski.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tapeteSierpinski(int i, int j, int size, int **M){

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