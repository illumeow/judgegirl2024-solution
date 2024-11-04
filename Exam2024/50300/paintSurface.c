#include <stdio.h>
#define max(a, b) ((a>=b)*(a)+(a<b)*b)
#define min(a, b) ((a<=b)*(a)+(a>b)*b)

void paintSurface(int *start, int *p1, int *p2, int L, int W, int H){
    int d1 = p1-start, d2 = p2-start;
    int tx1 = d1 / (W*H), tx2 = d2 / (W*H);
    int ty1 = (d1-(W*H*tx1)) / H, ty2 = (d2-(W*H*tx2)) / H;
    int tz1 = (d1-(W*H*tx1)) % H, tz2 = (d2-(W*H*tx2)) % H;
    int x1 = min(tx1, tx2);
    int x2 = max(tx1, tx2);
    int y1 = min(ty1, ty2);
    int y2 = max(ty1, ty2);
    int z1 = min(tz1, tz2);
    int z2 = max(tz1, tz2);
 
    for(int x = x1; x <= x2; x++){
        for(int y = y1; y <= y2; y++){
            *(start + x*W*H + y*H + z1) = 1;
            *(start + x*W*H + y*H + z2) = 1;
        }
    }
    for(int y = y1; y <= y2; y++){
        for(int z = z1; z <= z2; z++){
            *(start + x1*W*H + y*H + z) = 1;
            *(start + x2*W*H + y*H + z) = 1;
        }
    }
    for(int x = x1; x <= x2; x++){
        for(int z = z1; z <= z2; z++){
            *(start + x*W*H + y1*H + z) = 1;
            *(start + x*W*H + y2*H + z) = 1;
        }
    }
}