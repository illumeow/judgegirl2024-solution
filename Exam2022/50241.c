#include <stdio.h>
#include <stdint.h>

int main(){
    char *alphabets = "abcdefghijklmnopqrstuvwxyz";
    int n;
    scanf("%d", &n);
    int mask = 31;
    for(int i = 0; i < n; i++){
        uint64_t x;
        scanf("%llu", &x);
        for(int j = 0; j < 12; j++){
            printf("%c", alphabets[x & mask]);
            x >>= 5;
        }
    }
}