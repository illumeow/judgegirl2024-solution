#include <stdio.h>

int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    int x1 = x / 1000,
        x2 = x / 100 - 10 * x1,
        x3 = x / 10 - 100 * x1 - 10 * x2,
        x4 = x % 10,
        y1 = y / 1000,
        y2 = y / 100 - 10 * y1,
        y3 = y / 10 - 100 * y1 - 10 * y2,
        y4 = y % 10;
    // printf("x:%d %d %d %d\ny:%d %d %d %d\n", x1, x2, x3, x4, y1, y2, y3, y4);
    int m = 0, n = 0;
    if(x1 == y1) m++;
    if(x2 == y2) m++;
    if(x3 == y3) m++;
    if(x4 == y4) m++;
    if(x1 == y2 || x1 == y3 || x1 == y4) n++;
    if(x2 == y1 || x2 == y3 || x2 == y4) n++;
    if(x3 == y2 || x3 == y1 || x3 == y4) n++;
    if(x4 == y2 || x4 == y3 || x4 == y1) n++;
    printf("%dA%dB", m, n);
}