#include <stdio.h>
#include "dividePolynomial.h"

void dividePolynomial(int f[], int g[]){
    /* 
    deg(f) = f[0], deg(g) = g[0]
    deg(q) = deg(f) - deg(g), deg(r) <= deg(g)-1
    */
    for(int i = 1; i <= f[0]-g[0]+1; i++){
        int q = f[i]/g[1];
        f[i] = q;
        for(int j = 2; j <= g[0]+1; j++){
            f[i+j-1] -= g[j]*q;
        }
    }

    if(g[0] == 0){
        g[0] = g[1] = 0;
        return;
    }

    for(int i = 1; i <= g[0]; i++){
        g[i] = f[i+f[0]-g[0]+1];
    }

    f[0] -= g[0];
    g[0] --;

    int degr = g[0];
    for(int i = 1; i <= g[0]; i++){
        if(g[i]) break;
        degr--;
    }

    for(int i = g[0]+1-degr; i <= g[0]+1; i++){
        g[i-g[0]+degr] = g[i];
    }
    g[0] = degr;
}