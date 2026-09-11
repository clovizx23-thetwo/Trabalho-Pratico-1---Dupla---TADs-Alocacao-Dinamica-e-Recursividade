#include "montyhall.h"
#include <stdio.h>
#include <time.h>

int main(){
    int n;
    int s;

    scanf("%d %d", &n, &s);

    for(int criador = 0; criador < n; criador++){
        criarEventoMontyHall(s);
    }

    return 0;
}