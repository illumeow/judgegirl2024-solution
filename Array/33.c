#include <stdio.h>
#define MAXN 105

int main(){
    int n;
    scanf("%d", &n);
    int city[MAXN][MAXN] = {};
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &city[i][j]);
    
    #ifdef INPUT
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", city[i][j]);
        }
        printf("\n");  
    }
    #endif
    #ifdef DEBUG
    printf("==============\n");
    #endif

    // up down left right
    int dirx[4] = {-1, 1, 0, 0};
    int diry[4] = {0, 0, -1, 1};

    int intersection = 0, Tjunction = 0, turn = 0, dead = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!city[i][j]) continue;
            int count = 0;
            for(int k = 0; k < 4; k++)
                count += city[i + dirx[k]][j + diry[k]];
            
            #ifdef DEBUG
            printf("%d ", count);
            #endif
            
            switch(count){
                case 4: intersection++; break;
                case 3: Tjunction++; break;
                case 2:
                    if((city[i-1][j] == city[i+1][j]) || (city[i][j-1] == city[i][j+1])) break;
                    turn++; break;
                case 1: dead++; break;
                default: break;
            }
        }
        #ifdef DEBUG
        printf("\n");
        #endif
    }

    printf("%d\n%d\n%d\n%d", intersection, Tjunction, turn, dead);
}