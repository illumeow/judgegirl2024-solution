#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    int h = x/100;
    int t = x/10 - 10*h;
    int u = x-100*h-10*t;
    printf("%d\n%d\n%d", h, t, u);
}