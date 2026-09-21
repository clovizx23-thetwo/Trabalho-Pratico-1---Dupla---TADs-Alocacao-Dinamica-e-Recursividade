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
    int dimensaoDoInterno = size / 3;

    //montando o centro do Tapete [coord + tamanho] == dist. do centro
    for(int line = i + dimensaoDoInterno; line < i * dimensaoDoInterno; line++){
        for(int colum = j + dimensaoDoInterno; colum < j * dimensaoDoInterno; colum++){
            M[line][colum] = 0;
        }
    }

    //recursão para os 8 casos de 9, mas fora o centro
    tapeteSierpinski(i, j, dimensaoDoInterno, M);//superior esquerdo
    tapeteSierpinski(i, j + dimensaoDoInterno, dimensaoDoInterno, M);//superior du meio
    tapeteSierpinski(i, j + (2 * dimensaoDoInterno), dimensaoDoInterno, M);//superior direito

    tapeteSierpinski(i + dimensaoDoInterno, j, dimensaoDoInterno, M);//meio esquerdo
    //CNTRO TEÓRICO
    tapeteSierpinski(i + dimensaoDoInterno, j + (2 * dimensaoDoInterno), dimensaoDoInterno, M);//meio direito

    tapeteSierpinski(i + (2 * dimensaoDoInterno), j, dimensaoDoInterno, M); //inferior esquerdo
    tapeteSierpinski(i + (2 * dimensaoDoInterno), j + dimensaoDoInterno, dimensaoDoInterno, M);//inferior du meio 
    tapeteSierpinski(i + (2 * dimensaoDoInterno), j + (2 * dimensaoDoInterno), dimensaoDoInterno, M);//inferior direito
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