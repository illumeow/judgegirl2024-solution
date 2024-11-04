#include <stdio.h>

int main() {
    int h, w, d;
    scanf("%d%d%d", &h, &w, &d);
    printf("%d\n%d", 2*(h*w+w*d+d*h), (h*w*d));
}