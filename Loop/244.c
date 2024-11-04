#include <stdio.h>

int main(){
    int sp1, sp2, sp3, fp1, fp2, fp3;
    scanf("%d%d%d%d%d%d", &sp1, &sp2, &sp3, &fp1, &fp2, &fp3);
    int num, ans = 0;
    while(scanf("%d", &num) != EOF){
        if(num == sp1 || num == sp2 || num == sp3) ans += 2000000;
        else if(num == fp1 || num == fp2 || num == fp3) ans += 200000;
        else if(num % 10000000 == fp1 % 10000000|| num % 10000000 == fp2 % 10000000 || num % 10000000 == fp3 % 10000000) ans += 40000;
        else if(num % 1000000 == fp1 % 1000000|| num % 1000000 == fp2 % 1000000 || num % 1000000 == fp3 % 1000000) ans += 10000;
        else if(num % 100000 == fp1 % 100000|| num % 100000 == fp2 % 100000 || num % 100000 == fp3 % 100000) ans += 4000;
        else if(num % 10000 == fp1 % 10000|| num % 10000 == fp2 % 10000 || num % 10000 == fp3 % 10000) ans += 1000;
        else if(num % 1000 == fp1 % 1000|| num % 1000 == fp2 % 1000 || num % 1000 == fp3 % 1000) ans += 200;
    }
    printf("%d", ans);
}