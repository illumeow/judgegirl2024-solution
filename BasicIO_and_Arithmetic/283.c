#include <stdio.h>

int main() {
    int s, f, t;
    scanf("%d%d%d", &s, &f, &t);
    int x, y, z;
    z = s-t;
    y = 0.5*f-4*z-t;
    x = t-y;
    printf("%d\n%d\n%d", x, y, z);
}