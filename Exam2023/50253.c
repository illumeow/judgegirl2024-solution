#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int x1, y1, x2, y2, ans = 0;
    scanf("%d%d", &x1, &y1);
    int hx = x1, hy = y1;
    for(int i = 1; i < n; i++){
        scanf("%d%d", &x2, &y2);
        ans += x1*y2 - x2*y1;
        x1 = x2;
        y1 = y2;
    }
    x2 = hx, y2 = hy;
    ans += x1*y2 - x2*y1;
    printf("%d", ans);
}