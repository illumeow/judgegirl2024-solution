#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#define MAXN 1000
#define MAXK 100
#define MAXNdivK 50

void findPath(int idx, int edges[][MAXNdivK+5], int size[], int nowpath[], int pathlen, int k, int paths[][MAXK+5], int *pathNum){  // dfs
    // printf("%d(%d) ", idx, pathlen);
    nowpath[pathlen++] = idx;
    if(pathlen == k){
        // printf("\n");
        for(int i = 0; i < pathlen; i++)
            paths[*pathNum][i] = nowpath[i];
        (*pathNum)++;
        return;
    }
    for(int i = 0; i < size[idx]; i++){
        findPath(edges[idx][i], edges, size, nowpath, pathlen, k, paths, pathNum);
    }
}

void solve(int idx, int pathNum, int paths[][MAXK+5], int k, bool used[], int choosed[], int choosedNum, int *max, int best[]){
    if(idx == pathNum){
        if(choosedNum > *max){
            *max = choosedNum;
            for(int i = 0; i < choosedNum; i++)
                best[i] = choosed[i];
        }
        return;
    }
    bool valid = true;
    for(int i = 0; i < k; i++){
        if(used[paths[idx][i]]){
            valid = false;
            break;
        }
    }
    if(valid){
        choosed[choosedNum++] = idx;
        for(int i = 0; i < k; i++) used[paths[idx][i]] = true;
        solve(idx+1, pathNum, paths, k, used, choosed, choosedNum, max, best);
        for(int i = 0; i < k; i++) used[paths[idx][i]] = false;
        choosed[--choosedNum] = -1;
    }
    solve(idx+1, pathNum, paths, k, used, choosed, choosedNum, max, best);
}

int main(){
    int k, n;
    scanf("%d%d", &k, &n);
    // k sets, total n nodes, n/k nodes per set
    int node_per_set = n/k;
    int e;
    scanf("%d", &e);
    // adjacency list
    int edges[MAXN+5][MAXNdivK+5] = {{}};
    int size[MAXN+5] = {};
    for(int i = 0; i < e; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        edges[a][size[a]++] = b;
    }
    for(int i = n-node_per_set; i < n; i++)
        edges[i][size[i]++] = n;

    int paths[6000][MAXK+5], pathNum = 0, nowpath[MAXK+5] = {};
    #ifdef CHECK
    for(int i = 0; i < n; i++){
        printf("%d : ", i);
        for(int j = 0; j < size[i]; j++){
            printf("%d ", edges[i][j]);
        }
        printf("\n");
    }
    #endif
    for(int i = 0; i < node_per_set; i++)
        findPath(i, edges, size, nowpath, 0, k, paths, &pathNum);
    #ifdef CHECKPATH
    printf("pathNum = %d\n", pathNum);
    for(int i = 0; i < pathNum; i++){
        for(int j = 0; j < k; j++){
            printf("%d ", paths[i][j]);
        }
        printf("\n");
    }
    printf("=================\n");
    #endif
    bool used[MAXN+5] = {};
    int choosed[6005] = {}, best[6005] = {}, max = INT32_MIN;
    solve(0, pathNum, paths, k, used, choosed, 0, &max, best);
    for(int i = 0; i < max; i++){
        for(int j = 0; j < k; j++){
            printf("%d ", paths[best[i]][j]);
        }
        printf("\n");
    }
}