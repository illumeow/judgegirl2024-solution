#include <stdio.h>
#define MAXN 10000
#define MAXM 1000
#define max(a, b) (a>b)?a:b
#define min(a, b) (a<b)?a:b

/*
group the numbers by remainer acc. to m
-> r = 0..(m-1)
get sum, max, min of all groups. 
*/

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int numbers[MAXN];
    for(int i = 0; i < n; i++) scanf("%d", &numbers[i]);
    // all nums are non-neg
    int sum[MAXM] = {}, maxn[MAXM] = {}, minn[MAXM] = {};
    for(int i = 0; i < MAXM; i++){
        maxn[i] = -1;
        minn[i] = 10005;
    }
    for(int i = 0; i < n; i++){
        int r = numbers[i] % m;
        sum[r] += numbers[i]; // r = 0..(m-1)
        maxn[r] = max(maxn[r], numbers[i]);
        minn[r] = min(minn[r], numbers[i]);
        #ifdef DEBUG
        printf("num: %d\nr: %d\nsum: %d\nmax: %d\nmin: %d\n======\n", numbers[i], r, sum[r], maxn[r], minn[r]);
        #endif
    }
    for(int i = 0; i < m; i++) printf("%d %d %d\n", sum[i], maxn[i], minn[i]);
}