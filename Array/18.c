#include <stdio.h>
#define MAXN 100

int is_inside(int x, int y, int r, int c){
    if(x < 0 || x >= c || y < 0 || y >= r) return 0;
    return 1;
}

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

    // up down left right
    int dirx[4] = {-1, 1, 0, 0};
    int diry[4] = {0, 0, -1, 1};

    int ans[MAXN][MAXN] = {};
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            for(int k = 0; k < 4; k++){
                int ni = i + dirx[k], nj = j + diry[k];
                if(!is_inside(ni, nj, r, c)) continue;
                if(matrix[i][j] <= matrix[ni][nj]) ans[i][j] = 1;
            }
        }
    }

    int output[MAXN * MAXN] = {}, index = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!ans[i][j]){
                output[index] = matrix[i][j];
                index++;
            }
        }
    }

    for(int i = 0; i < index - 1; i++) printf("%d\n", output[i]);
    printf("%d", output[index - 1]);
}