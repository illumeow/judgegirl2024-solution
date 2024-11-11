#include <stdio.h>
#include <string.h>
#include <stdint.h>

void solve(int idx, char words[][55], int wordcost[], int n, int letters, int covered, int cost, int *mincost){
    if(idx == n){
        if(covered >= 26) *mincost = (cost < *mincost)? cost: *mincost;
        return;
    }

    // dont choose
    solve(idx+1, words, wordcost, n, letters, covered, cost, mincost);
    // choose words[idx]
    int tmp = letters;
    for(int i = 0; words[idx][i] != '\0'; i++){
        int mask = (1 << (words[idx][i] - 'a'));
        if((letters & mask) == 0){
            letters |= mask;
            covered++;
        }
    }
    solve(idx+1, words, wordcost, n, letters, covered, cost + wordcost[idx], mincost);
    letters = tmp;
}

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        char words[20][55];
        for(int i = 0; i < n; i++) scanf("%s", words[i]);
        int wordcost[20] = {};
        for(int i = 0; i < n; i++){
            char tmp[55];
            int used = 0;
            int idx = 0;
            for(int j = 0; words[i][j] != '\0'; j++){
                wordcost[i] += words[i][j] - 'a' + 1;
                int mask = (1 << (words[i][j] - 'a'));
                if((used & mask) == 0){
                    used |= mask;
                    tmp[idx++] = words[i][j];
                }
            }
            tmp[idx] = '\0';
            strcpy(words[i], tmp);
        }
        int min = INT32_MAX;
        solve(0, words, wordcost, n, 0, 0, 0, &min);
        printf("%d\n", min);
    }
}