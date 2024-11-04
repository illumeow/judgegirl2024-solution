#include <stdio.h>

int main() {
    int x1, y1 , x2, y2, x3, y3, x4, y4;
    scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    int cross1 = x1*y2-x2*y1, cross2 = x2*y3-x3*y2, cross3 = x3*y4-x4*y3, cross4 = x4*y1-x1*y4;
    if(cross1>0 && cross2>0 && cross3>0 && cross4>0) printf("1");
    else printf("0");
}

/* 
determine if the origin is in quadrilateral 
idk how does this method work :(
*/