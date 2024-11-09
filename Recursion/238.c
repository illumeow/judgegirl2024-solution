#include <stdio.h>

void solve(int k, int set[], int n, int pick, int *cnt){
    if(k <= 0){
        if(k == 0) (*cnt)++;
        return;
    }
    for(int i = pick + 1; i < n; i++)
        solve(k-set[i], set, n, i, cnt);
}

int main(){
    int n;
    scanf("%d", &n);
    int set[15] = {};
    for(int i = 0; i < n; i++) scanf("%d", &set[i]);
    int k;
    while(scanf("%d", &k) != EOF){
        int cnt = 0;
        for(int i = 0; i < n; i++)
            solve(k-set[i], set, n, i, &cnt);
        printf("%d\n", cnt);
    }
}