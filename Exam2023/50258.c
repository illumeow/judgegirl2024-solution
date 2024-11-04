#include <stdio.h>

int dis_square(int x1, int y1, int x2, int y2){
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

int main(){
    int xa, ya, ra, xb, yb, rb;
    scanf("%d%d%d%d%d%d", &xa, &ya, &ra, &xb, &yb, &rb);
    int x, y;
    while(scanf("%d%d", &x, &y) != EOF){
        int da = dis_square(x, y, xa, ya);
        int db = dis_square(x, y, xb, yb);
        if(da < ra*ra || db < rb*rb) printf("In\n");
        else if(da == ra*ra || db == rb*rb) printf("On\n");
        else printf("Out\n");
    }
}