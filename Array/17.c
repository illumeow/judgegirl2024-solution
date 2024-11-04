#include <stdio.h>
#define MAXN 100

int main(){
    int r, c, matrix[MAXN][MAXN] = {};
    scanf("%d%d", &r, &c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    #ifdef DEBUG
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    #endif

    int ans[MAXN] = {};
    for(int i = 0; i < c; i++){
        int sum = 0;
        for(int j = 0; j < r; j++){
            sum += matrix[j][i];
        }
        ans[i] = sum / r;
    }

    for(int i = 0; i < c - 1; i++) printf("%d\n", ans[i]);
    printf("%d", ans[c - 1]);
}