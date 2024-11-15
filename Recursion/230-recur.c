#include <stdio.h>
#define MAXN 20
#define MAXW 10000

int max(int a, int b){
    return (a > b)? a: b;
}

int solve(int idx, int w, int weight[], int value[], int n){
    if(idx == n) return 0;
    if(weight[idx] > w) return solve(idx+1, w, weight, value, n);
    return max(solve(idx+1, w, weight, value, n), solve(idx+1, w-weight[idx], weight, value, n) + value[idx]);
}

int main(){
    int n, W;
    scanf("%d%d", &n, &W);
    int weight[MAXN] = {}, value[MAXN] = {};
    for(int i = 0; i < n; i++)
        scanf("%d%d", &weight[i], &value[i]);
    printf("%d\n", solve(0, W, weight, value, n));
}