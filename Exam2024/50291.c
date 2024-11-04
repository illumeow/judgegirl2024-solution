#include <stdio.h>

int seg(int x1, int y1, int x2, int y2){
    int sx1 = 1*(x1 > 0) + (-1)*(x1 < 0);
    int sy1 = 1*(y1 > 0) + (-1)*(y1 < 0);
    int sx2 = 1*(x2 > 0) + (-1)*(x2 < 0);
    int sy2 = 1*(y2 > 0) + (-1)*(y2 < 0);

    // same quadrant
    if(sx1 == sx2 && sy1 == sy2) return 1;
    // diag
    if(sx1 != sx2 && sy1 != sy2 && x2*(y2-y1) != y2*(x2-x1)) return 3;
    // others
    return 2;
}

int solve(int x1, int y1, int x2, int y2, int x3, int y3){
    return seg(x1, y1, x2, y2) + seg(x2, y2, x3, y3) + seg(x3, y3, x1, y1);
}

int main(){
    int x1, y1, x2, y2, x3, y3;
    int x4, y4, x5, y5, x6, y6;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &x5, &y5, &x6, &y6);
    printf("%d\n%d", solve(x1, y1, x2, y2, x3, y3), solve(x4, y4, x5, y5, x6, y6));
}