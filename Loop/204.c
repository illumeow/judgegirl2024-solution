#include <stdio.h>

int getans(int x, int y, int w, int d){
    #ifdef DEBUG
    printf("(%d, %d) ", x, y);
    #endif
    // bottom
    if(x >= d) return y;
    // right
    else if(y >= w) return(w+d-1-x);
    // top
    else if(x < 0) return(w+d+w-1-y);
    // left
    else return(2*w+d+x);
}

int main(){
    int W, D;
    scanf("%d%d", &W, &D);
    int mirror[105][105] = {};
    for(int i = 0; i < D; i++){
        for(int j = 0; j < W; j++){
            scanf("%d", &mirror[i][j]);
        }
    }
    #ifdef INPUT
    for(int i = 0; i< D; i++){
        for(int j = 0; j < W; j++){
            printf("%d ", mirror[i][j]);
        }
        printf("\n");
    }
    #endif

    /* 00 01 02 ... 0(W-1)
       10 11 12 ... 1W-1)
       .. .. .. ... ..
       (D-1)0   ... (D-1)(W-1) */

    int x, y, dx, dy;
    // bottom: left to right
    #ifdef DEBUG
    printf("bottom\n");
    #endif
    for(int i = 0; i < W; i++){
        x = D-1;
        y = i;
        dx = -1;
        dy = 0;
        while(0 <= x && x < D && 0 <= y && y < W){
            if(mirror[x][y]){
                dx = (dx == -1)?0:-1;
                dy = (dy == 0)?1:0;
            }
            x += dx;
            y += dy;
        }
        printf("%d\n", getans(x, y, W, D));
    }
    // right: bottom to top
    #ifdef DEBUG
    printf("right\n");
    #endif
    for(int i = D-1; i >= 0; i--){
        x = i;
        y = W-1;
        dx = 0;
        dy = -1;
        while(0 <= x && x < D && 0 <= y && y < W){
            if(mirror[x][y]){
                dx = (dx == 0)?1:0;
                dy = (dy == -1)?0:-1;
            }
            x += dx;
            y += dy;
        }
        printf("%d\n", getans(x, y, W, D));
    }
    // top: right to left
    #ifdef DEBUG
    printf("top\n");
    #endif
    for(int i = W-1; i >= 0; i--){
        x = 0;
        y = i;
        dx = 1;
        dy = 0;
        while(0 <= x && x < D && 0 <= y && y < W){
            if(mirror[x][y]){
                dx = (dx == 1)?0:1;
                dy = (dy == 0)?-1:0;
            }
            x += dx;
            y += dy;
        }
        printf("%d\n", getans(x, y, W, D));
    }
    // left: top to down
    #ifdef DEBUG
    printf("left\n");
    #endif
    for(int i = 0; i < D; i++){
        x = i;
        y = 0;
        dx = 0;
        dy = 1;
        while(0 <= x && x < D && 0 <= y && y < W){
            if(mirror[x][y]){
                dx = (dx == 0)?-1:0;
                dy = (dy == 1)?0:1;
            }
            x += dx;
            y += dy;
        }
        printf("%d\n", getans(x, y, W, D));
    }   
}