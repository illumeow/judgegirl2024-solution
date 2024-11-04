#include <stdio.h>

int main(){
    long long int M, N, X1, Y1, E1, N1, F1, X2, Y2, E2, N2, F2;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld", &M, &N, &X1, &Y1, &E1, &N1, &F1, &X2, &Y2, &E2, &N2, &F2);
    #ifdef DEBUG
    printf("===\nt: 0\nR1: (%lld, %lld) N1: %lld E1: %lld\nR2: (%lld, %lld) N2: %lld E2: %lld\n", X1, Y1, N1, E1, X2, Y2, N2, E2);
    #endif
    /*
    horizontal: 0 ~ M-1
    vertical: 0 ~ N-1
    R1: N1 -> E1 -> N1 -> ... until F1 = 0
    R2: E2 -> N2 -> E2 -> ... until F2 = 0 
    move always up or right
    */
    long long int n1 = N1, e1 = E1, n2 = N2, e2 = E2, bk = 0, ceiling = (((F1>F2)?F1:F2) + 1);
    for(long long int t = 1; t < ceiling; t++){
        #ifdef DEBUG
        printf("===\nF1: %lld n1: %lld e1: %lld\nF2: %lld n2: %lld e2: %lld\n", F1, n1, e1, F2, n2, e2);
        #endif
        if(F1){
            if(n1){
                Y1++;
                n1--;
            }
            else if(e1){
                X1++;
                e1--;
            }
            
            if(n1 == 0 && e1 == 0){
                n1 = N1;
                e1 = E1;
            }

            if(X1 == M) X1 = 0;
            else if(Y1 == N) Y1 = 0;

            F1--;
        }
        if(F2){
            if(e2){
                X2++;
                e2--;
            }
            else if(n2){
                Y2++;
                n2--;
            }
            
            if(n2 == 0 && e2 == 0){
                n2 = N2;
                e2 = E2;
            }

            if(X2 == M) X2 = 0;
            else if(Y2 == N) Y2 = 0;

            F2--;
        }

        #ifdef DEBUG
        printf("t: %lld\nR1: (%lld, %lld)\nR2: (%lld, %lld)\n", t, X1, Y1, X2, Y2);
        #endif
        if(X1 == X2 && Y1 == Y2){
            printf("robots explode at time %lld", t);
            bk = 1;
            break;
        }
    }
    if(!bk) printf("robots will not explode");
}