#include <stdio.h>
#define MAXN 512
#define MAXK 128

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int input[MAXN+5][MAXN+5] = {};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &input[i][j]);
    int filter[MAXK+5][MAXK+5] = {};
    for(int i = 0; i < k; i++)
        for(int j = 0; j < k; j++)
            scanf("%d", &filter[i][j]);
    
    int output[MAXN-MAXK+1][MAXN-MAXK+1] = {};
    for(int i = 0; i < n-k+1; i++){
        for(int j = 0; j < n-k+1; j++){
            for(int s = 0; s < k; s++){
                for(int l = 0; l < k; l++){
                    output[i][j] += (input[s+i][l+j]*filter[s][l]);
                }
            }
        }
    }
    for(int i = 0; i < n-k+1; i++){
        for(int j = 0; j < n-k+1; j++){
            printf("%d%c", output[i][j], " \n"[j==n-k]);
        }
    }
}