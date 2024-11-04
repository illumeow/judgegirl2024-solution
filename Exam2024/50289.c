#include <stdio.h>

int main(){
    int L, W, l, w;
    scanf("%d%d%d%d", &L, &W, &l, &w);
    int lnum = L/l, wnum = W/w;
    printf("%d\n%d", lnum*wnum, L*W - lnum*wnum*l*w);
}