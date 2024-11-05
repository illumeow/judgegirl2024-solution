#include <stdio.h>

int sum_of_square(int n){
    if(n == 1) return 1;
    return n*n + sum_of_square(n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", sum_of_square(n));
}