#include <stdio.h>
#include <string.h>
#include <stdint.h>

void solve(int idx, char words[][55], int n, int letters, int covered, int cost, int *mincost){
    // printf("%s ", covered_letters);
    // printf("%d %d min: %d\n", strlen(covered_letters), covered, *mincost);
    if(idx == n){
        if(covered >= 26) *mincost = (cost < *mincost)? cost: *mincost;
        return;
    }

    // dont choose
    solve(idx+1, words, n, letters, covered, cost, mincost);
    // choose words[idx]
    int tmp = letters;
    for(int i = 0; words[idx][i] != '\0'; i++){
        int mask = (1 << (words[idx][i] - 'a'));
        if((letters & mask) == 0){
            letters |= mask;
            covered++;
        }
        cost += words[idx][i] - 'a' + 1;
    }
    solve(idx+1, words, n, letters, covered, cost, mincost);
    letters = tmp;
}

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        char words[20][55];
        for(int i = 0; i < n; i++) scanf("%s", words[i]);
        int min = INT32_MAX;
        solve(0, words, n, 0, 0, 0, &min);
        printf("%d\n", min);
    }
}