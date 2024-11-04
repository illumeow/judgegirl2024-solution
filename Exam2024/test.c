#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void num2str(int n, char *ret){
    for(int indx = 31; indx >= 0; indx--){
        int k = n & 1;
        ret[indx] = k + '0';
        n >>= 1;
    }
}

int main(){
    char ret[33];
    ret[32] = '\0';
    int n;
    scanf("%d", &n);
    num2str(n, ret);
    printf("%s\n", ret);
}
