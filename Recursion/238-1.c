#include <stdio.h>

void solve(int idx, int k, int set[], int n, int *ans){
    if(idx == n){
        if(k == 0) (*ans)++;
        return;
    }
    solve(idx+1, k-set[idx], set, n, ans);
    solve(idx+1, k, set, n, ans);
}

int main(){
    int n;
    scanf("%d", &n);
    int set[15] = {};
    for(int i = 0; i < n; i++) scanf("%d", &set[i]);
    int k, ans;
    while(scanf("%d", &k) != EOF){
        ans = 0;
        solve(0, k, set, n, &ans);
        printf("%d\n", ans);
    }
}