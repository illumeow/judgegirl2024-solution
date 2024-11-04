#include <stdio.h>
#define MAXN 10
#define MAXM 256

int check(int player_index, int m, int (*sum)[MAXN][2*MAXM+2]){
    for(int i = 0; i < 2*m+2; i++){
        if((*sum)[player_index][i] == m) return 1;   
    }
    return 0;
}


int main(){
    char name[MAXN][65];
    int board[MAXN][MAXM*MAXM][2];
    int sum[MAXN][2*MAXM+2] = {};

    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++){
        scanf("%s", name[i]);
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m; k++){
                int x;
                scanf("%d", &x);
                board[i][x][0] = j;
                board[i][x][1] = k;
            }
        }
    }

    for(int _ = 0; _ < m*m; _++){
        int x, flag = 0;
        scanf("%d", &x);
        for(int i = 0; i < n; i++){
            int px = board[i][x][0];
            int py = board[i][x][1];
            sum[i][px]++;
            sum[i][m+py]++;
            if(px == py) sum[i][2*m]++;
            if(px+py == m-1) sum[i][2*m+1]++;

            if(check(i, m, &sum)){
                if(!flag){
                    printf("%d", x);
                    flag++;
                }
                printf(" %s", name[i]);
            }
        }
        if(flag) break;
    }
}