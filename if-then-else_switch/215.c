#include <stdio.h>

int main() {
    int s, f, t;
    scanf("%d%d%d", &s, &f, &t);
    int x, y, z;
    z = s-t;
    y = 0.5*f-4*z-t;
    x = t-y;
    if(x<0||y<0||z<0||f%2!=0) printf("0");
    else printf("%d\n%d\n%d", x, y, z);
}