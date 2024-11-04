#include <stdio.h>
#include <stdbool.h>
#define MAXN 200
#define MAXM 200

typedef struct {
    int x1, y1, x2, y2;
} Rectangle;

bool intrersected(Rectangle r1, Rectangle r2){
    return !(r1.y2 < r2.y1 || r1.x2 < r2.x1 || r1.y1 > r2.y2 || r1.x1 > r2.x2);
}

bool in_rectangle(int x, int y, Rectangle r){
    return (r.x1 <= x && x <= r.x2 && r.y1 <= y && y <= r.y2);
}

int main(){
    int N, M, L, W, x, y, s, k;
    scanf("%d%d%d%d%d%d%d%d", &N, &M, &L, &W, &x, &y, &s, &k);
    int sunValue[MAXN][MAXM]= {};
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < M; j++)
            scanf("%d", &(sunValue[i][j]));
    /*
    sun: N x M
    shadow: L x W, moving down-left for k steps, each step = s
    (x, y) -> (x-s, y-s)
    */
    
    Rectangle sun, shadow;
    sun.x1 = sun.y1 = 0;
    sun.x2 = M-1; sun.y2 = N-1;
    shadow.x1 = x; shadow.y1 = y;
    shadow.x2 = x+W-1; shadow.y2 = y+L-1;

    int step;
    /* move shadow */
    for(step = 0; !intrersected(sun, shadow) && step < k; step++){
        shadow.x1 -= s; shadow.y1 -= s;
        shadow.x2 -= s; shadow.y2 -= s;
    }

    for(;; step++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                int num = (in_rectangle(j, N-1-i, shadow))?0:sunValue[i][j];
                printf("%d%c", num, " \n"[j==M-1]);
            }
        }

        /* move shadow */
        shadow.x1 -= s;
        shadow.y1 -= s;
        shadow.x2 -= s;
        shadow.y2 -= s;
        if(!intrersected(sun, shadow) || step == k) break;

        printf("\n");
    }
}