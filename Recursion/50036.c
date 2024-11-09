#include <stdio.h>

void solve(int idx, int m, int num[], int n, int k, int picked, int *ans){
    if(idx == n){
        if(picked >= k && m >= 0) (*ans)++;
        return;
    }
    solve(idx+1, m-num[idx], num, n, k, picked+1, ans);
    solve(idx+1, m, num, n, k, picked, ans);
}

int main(){
    int k, n, m, num[20];
    scanf("%d%d%d", &k, &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    int ans = 0;
    solve(0, m, num, n, k, 0, &ans);
    printf("%d\n", ans);
}