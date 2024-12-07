#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

int cmp(const void *A, const void *B){
    const ull *a = A, *b = B;
    int acnt = __builtin_popcountll(*a);
    int bcnt = __builtin_popcountll(*b);
    if(acnt != bcnt) return (acnt > bcnt) - (acnt < bcnt);
    return (*a > *b) - (*a < *b);
}

int main(){
    int n = 0;
    ull num[1005] = {};
    ull input;
    while(scanf("%llu", &input) == 1)
        num[n++] = input;
    qsort(num, n, sizeof(ull), cmp);
    for(int i = 0; i < n; i++) printf("%llu\n", num[i]);
}
