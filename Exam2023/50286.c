#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#define MAXN 64
#define MAXM 36

void solve(int idx, int m, int pairs[][2], bool edges[][MAXN+5], int n, bool choosed[], int choosed_num, bool best[], int *max){
    #ifdef DEBUG
    printf("%d : ", idx);
    for(int i = 0; i < m; i++)
        if(choosed[i]) printf("%d %d | ", pairs[i][0], pairs[i][1]);
    printf("\n");
    #endif
    if(choosed_num + m - idx <= *max) return;
    if(idx == m){
        #ifdef DEBUG
        printf("=========\n");
        #endif
        if(choosed_num > *max){
            *max = choosed_num;
            for(int i = 0; i < m; i++) best[i] = choosed[i];
        }
        return;
    }

    int cnt = 0;
    int u = pairs[idx][0], v = pairs[idx][1];  // u < v
    for(int i = 0; i < v && cnt < 2; i++){
        if(edges[u][i] && edges[v][i]){
            cnt = 0;
            // u and v have a mutual friend i
            // u < i < v || i < u < v
            #ifdef DEBUG
            printf("%d and %d have a mutual friend %d\n", u, v, i);
            #endif
            for(int j = 0; j < idx && cnt < 2; j++){
                if(choosed[j] && 
                ((pairs[j][0] == u && pairs[j][1] == i) || 
                 (pairs[j][0] == i && pairs[j][1] == v) ||
                 (pairs[j][0] == i && pairs[j][1] == u))) cnt++;
            }
        }
    }
    if(cnt < 2){
        choosed[idx] = true;
        solve(idx+1, m, pairs, edges, n, choosed, choosed_num+1, best, max);
        choosed[idx] = false;
    }
    solve(idx+1, m, pairs, edges, n, choosed, choosed_num, best, max);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int pairs[MAXM+5][2] = {{}};
    bool edges[MAXN+5][MAXN+5] = {{}};
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        pairs[i][0] = u;
        pairs[i][1] = v;
        edges[u][v] = edges[v][u] = true;
    }
    bool choosed[MAXM+5] = {}, best[MAXM+5] = {};
    int max = INT32_MIN;
    solve(0, m, pairs, edges, n, choosed, 0, best, &max);
    for(int i = 0; i < m; i++)
        if(best[i]) printf("%d %d\n", pairs[i][0], pairs[i][1]);
}