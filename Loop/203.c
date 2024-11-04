#include <stdio.h>

int main(){
    // dx, dy = 1 or -1
    int X, Y, x1, y1, x2, y2, dx1, dy1, dx2, dy2, t;
    scanf("%d%d%d%d%d%d%d%d%d%d%d", &X, &Y, &x1, &y1, &x2, &y2, &dx1, &dy1, &dx2, &dy2, &t);
    while(t--){
        // collide
        if(x1 == x2 && y1 == y2){
            #ifdef DEBUG
            printf("===\ncollide:\n1: (%d, %d)|(%d, %d)\n2: (%d, %d)|(%d, %d)\n", x1, y1, dx1, dy1, x2, y2, dx2, dy2);
            #endif
            // collide point at wall: same as corner
            if(x1 == 1 || x1 == X || y1 == 1 || y1 == Y){
                dx1 = -dx1; dy1 = -dy1;
                dx2 = -dx2; dy2 = -dy2;
                x1 += dx1; y1 += dy1;
                x2 += dx2; y2 += dy2;
                continue;
            }

            // collide in boundary: swap velocity
            int tmp;

            tmp = dx1;
            dx1 = dx2;
            dx2 = tmp;

            tmp = dy1;
            dy1 = dy2;
            dy2 = tmp;

            x1 += dx1; y1 += dy1;
            x2 += dx2; y2 += dy2;
            continue;
        }

        // did not collide
        // hit corner
        if((x1 == 1 && y1 == 1) || (x1 == 1 && y1 == Y) || (x1 == X && y1 == Y) || (x1 == X && y1 == 1)){
            #ifdef DEBUG
            printf("===\n1 corner\n1: (%d, %d)|(%d, %d)\n", x1, y1, dx1, dy1);
            #endif
            dx1 = -dx1; dy1 = -dy1;
        }
        // hit wall
        else if(x1 == 1 || x1 == X){
            #ifdef DEBUG
            printf("===\n1 lr wall\n1: (%d, %d)|(%d, %d)\n", x1, y1, dx1, dy1);
            #endif
            dx1 = -dx1;
        }
        else if(y1 == 1 || y1 == Y){
            #ifdef DEBUG
            printf("===\n1 ud wall\n1: (%d, %d)|(%d, %d)\n", x1, y1, dx1, dy1);
            #endif
            dy1 = -dy1;
        }

        // hit corner
        if((x2 == 1 && y2 == 1) || (x2 == 1 && y2 == Y) || (x2 == X && y2 == Y) || (x2 == X && y2 == 1)){
            #ifdef DEBUG
            printf("===\n2 corner\n2: (%d, %d)|(%d, %d)\n", x2, y2, dx2, dy2);
            #endif
            dx2 = -dx2; dy2 = -dy2;
        }
        // hit wall
        else if(x2 == 1 || x2 == X){
            #ifdef DEBUG
            printf("===\n2 lr wall\n2: (%d, %d)|(%d, %d)\n", x2, y2, dx2, dy2);
            #endif
            dx2 = -dx2;
        }
        else if(y2 == 1 || y2 == Y){
            #ifdef DEBUG
            printf("===\n2 ud wall\n2: (%d, %d)|(%d, %d)\n", x2, y2, dx2, dy2);
            #endif
            dy2 = -dy2;
        }

        x1 += dx1; y1 += dy1;
        x2 += dx2; y2 += dy2;
    }
    printf("%d\n%d\n%d\n%d", x1, y1, x2, y2);
}