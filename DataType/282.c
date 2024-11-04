#include <stdio.h>

int main(){
    long long n;
    while(scanf("%lld", &n) != EOF){
        int bit = 0;
        while(n > 0){
            if(n & 1) bit++;
            n >>= 1;
        }
        printf("%d\n", bit);
    }
}