#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int maxbit = 0;
        int bit = 0;
        while(n > 0){
            if(n & 1) bit++;
            else{
                maxbit = (bit > maxbit)? bit: maxbit;
                bit = 0;
            }
            n >>= 1;
        }
        maxbit = (bit > maxbit)? bit: maxbit;
        printf("%d\n", maxbit);
    }
}