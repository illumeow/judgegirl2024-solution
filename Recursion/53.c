#include <stdio.h>
#include <stdlib.h>

void solve(int idx, int n, int permu[], int used[], int num[]){
    if(idx == n){
        for(int i = 0; i < n; i++) printf("%d%c", num[permu[i]], " \n"[i==n-1]);
        return;
    }

    for(int i = 0; i < n; i++){
        if(!used[i]){
            used[i] = 1;
            permu[idx] = i;
            solve(idx+1, n, permu, used, num);
            used[i] = 0;
        }
    }
}

int cmp(const void *A, const void *B){
    const int *a = (const int *)A;
    const int *b = (const int *)B;
    return (*a > *b) - (*a < *b);
}

int main(){
    int n, num[10] = {};
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    qsort(num, n, sizeof(int), cmp);
    int permu[10], used[10] = {};
    solve(0, n, permu, used, num);
}