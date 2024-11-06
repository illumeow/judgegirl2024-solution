#include <stdio.h>
typedef long long ll;

int main(){
    int n;
    scanf("%d", &n);
    ll D, a, b, c, A, B, C;
    int flag = 0;
    for(int t = 0; t < n; t++){
        flag = 0;
        scanf("%lld%lld%lld%lld%lld%lld%lld", &D, &a, &b, &c, &A, &B, &C);
        for(ll i = 0; i <= a; i++){
            for(ll j = 0; j <= b; j++){
                for(ll k = 0; k <= c; k++){
                    if(i*A + j*B + k*C == D){
                        printf("yes\n");
                        flag = 1;
                    }
                    if(flag) break;
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag) continue;
        printf("no\n");
    }
}