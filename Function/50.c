#include <stdio.h>
#define max(a, b) (a>b)?a:b
#define min(a, b) (a<b)?a:b

typedef struct {
    int x1, y1, x2, y2;
} Rectangle;

int get_area(Rectangle a){
    return (a.x2-a.x1)*(a.y2-a.y1);
}

Rectangle intersect_rectangle(Rectangle a, Rectangle b){
    Rectangle ret;
    /* no intersect */
    if(a.x2 <= b.x1 || b.x2 <= a.x1 || a.y2 <= b.y1 || b.y2 <= a.y1) ret.x1 = ret.y1 = ret.x2 = ret.y2 = 0;
    else{
        ret.x1 = max(a.x1, b.x1);
        ret.y1 = max(a.y1, b.y1);
        ret.x2 = min(a.x2, b.x2);
        ret.y2 = min(a.y2, b.y2);
    }
    return ret;
}

int main(){
    Rectangle A, B, C;
    scanf("%d%d%d%d", &A.x1, &A.y1, &A.x2, &A.y2);
    scanf("%d%d%d%d", &B.x1, &B.y1, &B.x2, &B.y2);
    scanf("%d%d%d%d", &C.x1, &C.y1, &C.x2, &C.y2);
    printf("%d", get_area(A)+get_area(B)+get_area(C)
                -get_area(intersect_rectangle(A, B))-get_area(intersect_rectangle(B, C))-get_area(intersect_rectangle(C, A))
                +get_area(intersect_rectangle(intersect_rectangle(A, B), C)));
}