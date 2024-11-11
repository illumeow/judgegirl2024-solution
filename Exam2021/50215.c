#include <stdio.h>
#include <string.h>
#include <stdint.h>

void solve(int idx, int wordint[], int wordcost[], int n, int used_letters, int cost, int *mincost){
    if(idx == n){
        if(__builtin_popcount(used_letters) >= 26) *mincost = (cost < *mincost)? cost: *mincost;
        return;
    }

    // dont choose
    solve(idx+1, wordint, wordcost, n, used_letters, cost, mincost);
    // choose words[idx]
    int tmp = used_letters;
    solve(idx+1, wordint, wordcost, n, used_letters | wordint[idx], cost + wordcost[idx], mincost);
    used_letters = tmp;
}

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        char words[20][55];
        for(int i = 0; i < n; i++) scanf("%s", words[i]);
        int wordint[20] = {}, wordcost[20] = {};
        for(int i = 0; i < n; i++){
            for(int j = 0; words[i][j] != '\0'; j++){
                wordcost[i] += words[i][j] - 'a' + 1;
                wordint[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        int min = INT32_MAX;
        solve(0, wordint, wordcost, n, 0, 0, &min);
        printf("%d\n", min);
    }
}