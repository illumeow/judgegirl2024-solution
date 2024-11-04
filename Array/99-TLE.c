#include <stdio.h>
#define MAXN 10
#define MAXM 256

typedef struct{
    // length of name <= 64 char
    char name[65];
    int board[MAXM][MAXM];
    int sum[2*MAXM+2];
} Player;

int check(Player p, int m){
    for(int i = 0; i < 2*m+2; i++){
        if(!p.sum[i]) return 1;
    }
    return 0;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    // n players, each have a m*m board
    // n = 1..10, m = 1..256
    Player players[MAXN];
    for(int i = 0; i < n; i++){
        for(int j; j < 2*MAXM+2; j++){
            players[i].sum[j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        scanf("%s", players[i].name);
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m; k++){
                int x;
                scanf("%d", &x);
                players[i].board[j][k] = x;
                players[i].sum[k] += x;
                players[i].sum[j+m] += x;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            players[i].sum[2*m] += players[i].board[j][j];
        }
        for(int j = 0; j < m; j++){
            players[i].sum[2*m+1] += players[i].board[(m-1)-j][j];
        }
    }

    #ifdef INPUT
    for(int i = 0; i < n; i++){
        printf("%s\n", players[i].name);
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m; k++){
                printf("%d ", players[i].board[j][k]);
            }
            printf("\n");
        }
        for(int j = 0; j < 2*m+2; j++){
            printf("%d ", players[i].sum[j]);
        }
        printf("\n");
    }
    #endif

    // input: m*m nums in call order
    for(int _ = 0; _ < m*m; _++){
        int x, flag = 0;
        scanf("%d", &x);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < m; k++){
                    if(players[i].board[j][k] == x){
                        players[i].sum[k] -= x;
                        players[i].sum[j+m] -= x;
                        if(j == k) players[i].sum[2*m] -= x;
                        if(j+k == m-1) players[i].sum[2*m+1] -= x;
                    }
                }
            }
            if(check(players[i], m)){
                if(!flag){
                    flag = 1;
                    printf("%d", x);
                }
                printf(" %s", players[i].name);
            }
        }
        if(flag) break;
    }
}