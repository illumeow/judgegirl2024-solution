#include <stdio.h>
#define MAXN 500
 
int main(){
    int n;
    scanf("%d", &n);
    int weight[MAXN][MAXN] = {};
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &(weight[i][j]));
    /* weight[i][j] = weight of i-th to j-th */
 
    int length[MAXN] = {};
    for(int i = 0; i < n; i++){
        int now = i, next = 0;
        int visited[MAXN] = {};
        visited[now] = 1;
 
        for(int cnt = 0; cnt < n-1; cnt++){
            int minw = 1000005;
            for(int j = 0; j < n; j++){
                if((!visited[j]) && (weight[now][j] <= minw)){
                    next = j;
                    minw = weight[now][j];
                }
                // printf("%d %d | ", next, minw);
            }
            // printf("%d -> %d, ", now, next);
            length[i] += minw;
            now = next;
            visited[now] = 1;
        }
        length[i] += weight[next][i];
        // printf("\n");
    }
 
    int ans, anslen = 1e9;
    for(int i = 0; i < n; i++){
        if(length[i] <= anslen){
            anslen = length[i];
            ans = i+1;
        }
    }
    printf("%d %d\n", ans, anslen);
}