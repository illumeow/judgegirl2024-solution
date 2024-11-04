#include <stdio.h>
#include <stdlib.h>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

typedef struct {
    int x, y;
} Point;

int cmp(void const * A, void const * B){
    const Point *a = A;
    const Point *b = B;
    if(a->x == b->x)
        return (a->y > b->y) - (a->y < b->y);
    return (a->x > b->x) - (a->x < b->x);
}

int count(int x, int y, int dir, int grid[105][105]){
    int ret = 0;
    int dirx[4] = {-1, 1, 0, 0};
    int diry[4] = {0, 0, -1, 1};
    while(grid[x][y]){
        ret++;
        x += dirx[dir];
        y += diry[dir];
    }
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    int grid[105][105] = {{}};
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &grid[i][j]);

    int m;
    scanf("%d", &m);
    Point corners[m];
    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        corners[i].x = x+1;
        corners[i].y = y+1;
    }
    
    qsort(corners, m, sizeof(Point), cmp);
    // for(int i = 0; i < m; i++) printf("%d %d\n", corners[i].x, corners[i].y);

    for(int i = 0; i < m; i++){
        int x = corners[i].x, y = corners[i].y;

        int type, vcnt, hcnt;
        if(grid[x-1][y] && grid[x][y+1]){
            type = 0;
            vcnt = count(x, y, UP, grid);
            hcnt = count(x, y, RIGHT, grid);
        }
        else if(grid[x-1][y] && grid[x][y-1]){
            type = 1;
            vcnt = count(x, y, UP, grid);
            hcnt = count(x, y, LEFT, grid);
        }
        else if(grid[x+1][y] && grid[x][y-1]){
            type = 2;
            vcnt = count(x, y, DOWN, grid);
            hcnt = count(x, y, LEFT, grid);
        }
        else if(grid[x+1][y] && grid[x][y+1]){
            type = 3;
            vcnt = count(x, y, DOWN, grid);
            hcnt = count(x, y, RIGHT, grid);
        }

        printf("%d %d %d\n", type, vcnt, hcnt);
    }
}