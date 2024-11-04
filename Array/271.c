#include <stdio.h>

int main(){
    /*
    The number of coefficients in a polynomial is no more than 100. 
    The coefficients are positive and no more than 100.
    */
    // store in decending order -> f[i] = coe of x^i
    int n, f[100] = {}, m, g[100] = {};
    scanf("%d", &n);
    for(int i = n-1; i >= 0; i--) scanf("%d", &f[i]);
    scanf("%d", &m);
    for(int i = m-1; i >= 0; i--) scanf("%d", &g[i]);

    int ans[10000] = {};
    for(int i = 0; i <= (m-1)+(n-1); i++){
        for(int p1 = 0; p1 <= i; p1++){
            int p2 = i - p1;
            if(p1 < n && p2 < m){
                ans[i] += f[p1] * g[p2];
            }
        }
    }
    for(int i = (m-1)+(n-1); i > 0; i--) printf("%d ", ans[i]);
    printf("%d", ans[0]);
}