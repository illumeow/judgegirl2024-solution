#include <stdio.h>

int main(){
    int w, a, b, c, d, e;
    scanf("%d%d%d%d%d%d", &w, &a, &b, &c, &d, &e);
    int k = (a+b+c+d+d+e+e+2)*(b > 0)+(a+c+e+e+2)*(b == 0 && e>=d)+(a+c+d+d+2)*(b == 0 && e<d);
    printf("%d", w*w + k*k);
}