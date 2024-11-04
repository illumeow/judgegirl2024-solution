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

int main(){
    int n;
    scanf("%d", &n);
    int x[10005] = {}, y[10005] = {};
    for(int i = 0; i < n; i++)
        scanf("%d%d", &x[i], &y[i]);
    int sum = 0;
    for(int i = 1; i < n; i++)
        sum += seg(x[0], y[0], x[i], y[i]);
    for(int i = 1; i < n-1; i++)
        sum += seg(x[i], y[i], x[i+1], y[i+1]);
    printf("%d\n", sum);
}