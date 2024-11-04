#include <stdio.h>

int main(){
    int num[1005] = {};
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    for(int i = n-1; i > 0; i--) printf("%d ", num[i]);
    printf("%d", num[0]);
}