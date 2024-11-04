#include <stdio.h>
#define MAXN 200000
int main(){
    int N, M;
    scanf("%d", &N);
    int num[MAXN] = {}, ans[MAXN] = {};
    for(int i = 0; i < N; i++) scanf("%d", &num[i]);
    scanf("%d", &M);

    for(int i = 0; i < N; i++) ans[num[i] % M]++;
    
    for(int i = 0; i < M - 1; i++) printf("%d\n", ans[i]);
    printf("%d\n", ans[M - 1]);
}