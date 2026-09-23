//26.1.4147
//26.1.4048

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// cores e formato de texto
#define ANSI_RESET            "\x1b[0m"  // desativa os efeitos anteriores
#define ANSI_BOLD             "\x1b[1m"  // coloca o texto em negrito
#define ANSI_COLOR_BLACK      "\x1b[30m"
#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_CYAN       "\x1b[36m"
#define ANSI_COLOR_WHITE      "\x1b[37m"
#define ANSI_BG_COLOR_BLACK   "\x1b[40m"
#define ANSI_BG_COLOR_RED     "\x1b[41m"
#define ANSI_BG_COLOR_GREEN   "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW  "\x1b[43m"
#define ANSI_BG_COLOR_BLUE    "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_CYAN    "\x1b[46m"
#define ANSI_BG_COLOR_WHITE   "\x1b[47m"

// macros para facilitar o uso
#define BOLD(string)       ANSI_BOLD             string ANSI_RESET
#define BLACK(string)      ANSI_COLOR_BLACK      string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define RED(string)        ANSI_COLOR_RED        string ANSI_RESET
#define GREEN(string)      ANSI_COLOR_GREEN      string ANSI_RESET
#define YELLOW(string)     ANSI_COLOR_YELLOW     string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define MAGENTA(string)    ANSI_COLOR_MAGENTA    string ANSI_RESET
#define CYAN(string)       ANSI_COLOR_CYAN       string ANSI_RESET
#define WHITE(string)      ANSI_COLOR_WHITE      string ANSI_RESET
#define BG_BLACK(string)   ANSI_BG_COLOR_BLACK   string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_RED(string)     ANSI_BG_COLOR_RED     string ANSI_RESET
#define BG_GREEN(string)   ANSI_BG_COLOR_GREEN   string ANSI_RESET
#define BG_YELLOW(string)  ANSI_BG_COLOR_YELLOW  string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
#define BG_CYAN(string)    ANSI_BG_COLOR_CYAN    string ANSI_RESET
#define BG_WHITE(string)   ANSI_BG_COLOR_WHITE   string ANSI_RESET

void tapeteSierpinski(int i, int j, int size, int **M){
    if(size == 1){
        M[i][j] = 1;
        return;
    }

    //cada quadradinho tem tamanho [size / 3], pq são 9 quadradinhos o tapete total
    int dimensaoDoInterno = size / 3;

    //montando o centro do Tapete [coord + tamanho] == dist. do centro
    //
    for(int line = i + dimensaoDoInterno; line <  i + (2 * dimensaoDoInterno); line++){
        for(int colum = j + dimensaoDoInterno; colum <  j + (2 * dimensaoDoInterno); colum++){
            M[line][colum] = 0;
        }
    }

    //recursão para os 8 casos de 9, mas fora o centro
    tapeteSierpinski(i, j, dimensaoDoInterno, M);//superior esquerdo
    tapeteSierpinski(i, j + dimensaoDoInterno, dimensaoDoInterno, M);//superior du meio
    tapeteSierpinski(i, j + (2 * dimensaoDoInterno), dimensaoDoInterno, M);//superior direito

    tapeteSierpinski(i + dimensaoDoInterno, j, dimensaoDoInterno, M);//meio esquerdo
    //CNTRO ZERADO
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

void mainSierpinski() {
    printf("\n\n========TAPETE DE SIERPINSKI========");
    int p, ns;

    printf("\n\nDigite o numero para ser o expoente da matriz: ");
    scanf("%d", &p);
        //calculando os laodos da matriz
    ns = pow(3, p);
    printf("\nO valor de n eh: %d\n\n", ns);

    int **matN = criarMatriz(ns);

    if(matN != NULL){
            
        tapeteSierpinski(0, 0, ns, matN);

        for(int line2 = 0; line2 < ns; line2++){
            for(int col2 = 0; col2 < ns; col2++){
                
                if(matN[line2][col2] == 0){
                    printf(" ");
                }else{
                    printf(WHITE("1"));
                }

                if(col2 < ns-1)
                    printf(" ");
            }
            printf("\n");
        }
        printf("\n");

        liberaSierpinski(matN, ns);
    }
}