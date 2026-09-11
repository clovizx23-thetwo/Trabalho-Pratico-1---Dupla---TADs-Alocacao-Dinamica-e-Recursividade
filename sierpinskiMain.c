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
    return 0;
}