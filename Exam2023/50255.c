#include <stdio.h>

typedef struct Point{
    int x, y;
} Point;

int dis_square(Point a, Point b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int main(){
    Point a, b, c, d;
    while(scanf("%d%d%d%d%d%d%d%d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y) != EOF){
        int dis[3], ans = 0;
        dis[0] = dis_square(a, d), dis[1] = dis_square(b, d), dis[2] = dis_square(c, d);
        if(dis[0] < dis[1] && dis[0] < dis[2]) ans = 1;
        else if(dis[1] < dis[0] && dis[1] < dis[2]) ans = 2;
        else if(dis[2] < dis[1] && dis[2] < dis[0]) ans = 3;
        else if(dis[0] == dis[1] && dis[0] != dis[2]) ans = 4;
        else if(dis[0] == dis[2] && dis[0] != dis[1]) ans = 5;
        else if(dis[1] == dis[2] && dis[0] != dis[1]) ans = 6;

        printf("%d ", ans);
    }
    // printf("%d", ans);
}
