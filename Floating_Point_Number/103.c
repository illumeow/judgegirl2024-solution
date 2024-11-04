#include <stdio.h>
#define MAXN 16

int main(){
    int n;  /* 1 <= n <= 16 */
    scanf("%d", &n);
    double A[MAXN][MAXN], X[MAXN], Y[MAXN];

    /* A is upper triangular */
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);
    
    for(int i = 0; i < n; i++)
        scanf("%lf", &Y[i]);

    X[n-1] = Y[n-1]/A[n-1][n-1];
    for(int k = n-2; k >= 0; k--){
        double temp = 0;
        for(int i = k+1; i < n; i++){
           temp +=  A[k][i]*X[i];
        }
        X[k] = (Y[k]-temp)/A[k][k];
    }
    for(int i = 0; i < n; i++)
        printf("%f\n", X[i]);
}