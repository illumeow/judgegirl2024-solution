#include <stdio.h>
#define ll long long

ll factorial(int n){
    if(n == 0) return 1;
    ll ret = 1;
    for(int i = 2; i <= n; i++) ret *= i;
    return ret;
}

ll Comb(int n, int r){
    return factorial(n)/(factorial(r)*factorial(n-r));
}

int main(){
    /* nC0 to nCm */
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= m; i++) ans += Comb(n, i);
    printf("%d", ans);
}