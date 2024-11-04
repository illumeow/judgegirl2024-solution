#include <stdio.h>

int main(){
    int points[100][2];
    int n = 0;
    while(scanf("%d %d", &points[n][0], &points[n][1]) != EOF){n++;}
    // find (minx, miny) and (maxx, maxy)
    int minx = 10000, miny = 10000, maxx = -10000, maxy = -10000;
    for(int i = 0; i < n; i++){
        int x = points[i][0], y = points[i][1];
        minx = (minx < x)?minx:x;
        miny = (miny < y)?miny:y;
        maxx = (maxx > x)?maxx:x;
        maxy = (maxy > y)?maxy:y;
    }
    printf("%d", (maxx - minx)*(maxy - miny));
}