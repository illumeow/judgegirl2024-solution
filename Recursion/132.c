#include <stdio.h>
#include <stdbool.h>

bool valid(int P, int adj[][2], int color[]){
    for(int i = 0; i < P; i++)
        if(color[adj[i][0]] != 0 && color[adj[i][0]] == color[adj[i][1]])
            return false; 
    return true;
}

bool solve(int idx, int N, int C, int P, int adj[][2], int color[]){
    if(!valid(P, adj, color)) return false;
    if(idx == N) return true;
    for(int i = 1; i <= C; i++){
        color[idx] = i;
        for(int j = idx+1; j < N; j++) color[j] = 0;
        if(solve(idx+1, N, C, P, adj, color)) return true;
    }
    return false;
}

int main(){
    int N, C, P;
    scanf("%d%d%d", &N, &C, &P);
    int adj_countries[200][2] = {};
    for(int i = 0; i < P; i++) scanf("%d%d", &adj_countries[i][0], &adj_countries[i][1]);
    int color[20] = {};
    if(solve(0, N, C, P, adj_countries, color)){
        for(int i = 0; i < N; i++) printf("%d\n", color[i]);
    }else printf("no solution.\n");
}