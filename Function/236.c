#include <stdio.h>


int gcd(int a, int b){
    int i = (a>b)?a:b;
    int j = (a>b)?b:a;
    while(i % j != 0){
        int r = i % j;
        i = j;
        j = r;
    }
    return j;
}

int main(){
    int n, lcm = 1;
    while(scanf("%d", &n) != EOF){
        lcm = (lcm*n)/gcd(lcm, n);
    }
    printf("%d", lcm);
}