#include <stdio.h>

void printll(unsigned long long n) {
    for (int i = 63; i >= 0; i--) {
        printf("%llu", (n >> i) & 1);
    }
    printf("\n");
}

int main(){
    unsigned long long x;
    scanf("%llu", &x);
    printll(x);
}
