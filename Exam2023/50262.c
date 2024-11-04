#include <stdio.h>
#define MAXN 50005

typedef struct {
    int r, c;
} Point;

int dis2(Point a, Point b){
    return (a.r - b.r)*(a.r - b.r) + (a.c - b.c)*(a.c - b.c);
}

int main(){
    int n;
    scanf("%d", &n);
    Point x[MAXN];
    for(int i = 0; i < n; i++)
        scanf("%d%d", &x[i].r, &x[i].c);
    Point y;
    scanf("%d%d", &y.r, &y.c);

    int mindis = 1e9;
    for(int i = 0; i < n; i++)
        mindis = mindis*(mindis <= dis2(x[i], y)) + dis2(x[i], y)*(mindis > dis2(x[i], y));
    
    for(int i = 0; i < n; i++){
        if(dis2(x[i], y) == mindis)
            printf("%d\n", i);
    }
}