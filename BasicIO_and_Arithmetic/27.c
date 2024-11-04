#include <stdio.h>

int main() {
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    int osurface = 2*(a*b+b*c+c*a);
    int ovolume = a*b*c;
    int surface = osurface + (a-2*e)*d*8 + (c-2*e)*d*8 + (b-2*e)*d*8;
    int volume = ovolume - (a-2*e)*(b-2*e)*d*2 - (a-2*e)*(c-2*e)*d*2 - (b-2*e)*(c-2*e)*d*2;
    printf("%d\n%d", surface, volume);
}