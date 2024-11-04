#include <stdio.h>

typedef struct {
    int x1, y1, x2, y2;
} Rectangle;

int rec_area(Rectangle r){
    return (r.x2 - r.x1) * (r.y2 - r.y1);
}

int main(){
    int n;
    scanf("%d", &n);
    int x, y, w, h;
    scanf("%d%d%d%d", &x, &y, &w, &h);
    Rectangle r1, r2;
    r1.x1 = x, r1.y1 = y, r1.x2 = x+w, r1.y2 = y+h;
    int area = rec_area(r1);
    for(int i = 1; i < n; i++){
        scanf("%d%d%d%d", &x, &y, &w, &h);
        r2.x1 = x, r2.y1 = y, r2.x2 = x+w, r2.y2 = y+h;
        Rectangle intersect;
        intersect.x1 = r2.x1, intersect.y1 = r2.y1;
        intersect.x2 = r1.x2, intersect.y2 = r1.y2;
        area += (rec_area(r2) - rec_area(intersect));
        r1 = r2;
    }
    printf("%d", area);
}