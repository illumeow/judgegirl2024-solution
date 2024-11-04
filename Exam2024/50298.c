#include <stdio.h>
#define max(a, b) ((a)*(a>b)+(b)*(a<=b))
#define min(a, b) ((a)*(a<b)+(b)*(a>=b))
 
typedef struct {
    int x1, y1, x2, y2;
} Rectangle;
 
int area(Rectangle r){
    return (r.x2-r.x1)*(r.y2-r.y1);
}
Rectangle intersect(Rectangle r1, Rectangle r2){
    Rectangle tmp;
    if(r1.x1 >= r2.x2 || r1.y1 >= r2.y2 || r1.y2 <= r2.y1 || r1.x2 <= r2.x1){
        tmp.x1 = tmp.y1 = tmp.x2 = tmp.y2 = 0;
        return tmp;
    }
    tmp.x1 = max(r1.x1, r2.x1);
    tmp.y1 = max(r1.y1, r2.y1);
    tmp.x2 = min(r1.x2, r2.x2);
    tmp.y2 = min(r1.y2, r2.y2);
    return tmp;
}
 
int main(){
    Rectangle r1, r2;
    scanf("%d%d%d%d", &r1.x1, &r1.y1, &r1.x2, &r1.y2);
    scanf("%d%d%d%d", &r2.x1, &r2.y1, &r2.x2, &r2.y2);
    Rectangle inter = intersect(r1, r2);
    Rectangle q1, q2, q3, q4;
    q1.x1 = 0, q1.y1 = 0, q1.x2 = 10005, q1.y2 = 10005;
    q2.x1 = -10005, q2.y1 = 0, q2.x2 = 0, q2.y2 = 10005;
    q3.x1 = -10005, q3.y1 = -10005, q3.x2 = 0; q3.y2 = 0;
    q4.x1 = 0, q4.y1 = -10005, q4.x2 = 10005; q4.y2 = 0;
    printf("%d\n%d\n%d\n%d", area(intersect(r1, q1))+area(intersect(r2, q1))-area(intersect(inter, q1)), 
                             area(intersect(r1, q2))+area(intersect(r2, q2))-area(intersect(inter, q2)),    
                             area(intersect(r1, q3))+area(intersect(r2, q3))-area(intersect(inter, q3)),
                             area(intersect(r1, q4))+area(intersect(r2, q4))-area(intersect(inter, q4)));
    return 0;
}