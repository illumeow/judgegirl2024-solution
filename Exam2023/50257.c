#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n != 1){
        printf("%d\n", n);
        n = (3*n+1)*(n&1) + (n/2)*(!(n&1));
    }
    printf("1");
}