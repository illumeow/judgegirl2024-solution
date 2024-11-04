#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// The four points may be given in any order.

typedef struct {
    float x, y;
    double angle;
} Point;

Point ref;

int dis(Point p1, Point p2) {
    return((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

int findLowestPoint(Point points[], int n) {
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[minIdx].y || (points[i].y == points[minIdx].y && points[i].x < points[minIdx].x)) {
            minIdx = i;
        }
    }
    return minIdx;
}

double findAngle(Point p) {
    return atan2(p.y - ref.y, p.x - ref.x);
}

int cmp(const void *a, const void *b){
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;

    if (p1->angle > p2->angle) return 1;
    if (p1->angle < p2->angle) return -1;
    return 0;
}


int main() {
    int n;
    scanf("%d", &n);
    Point points[4];
    int sides[6], indx;

    while(n--) {
        for(int i = 0; i < 4; i++) scanf("%f%f", &points[i].x, &points[i].y);

        int lowestIdx = findLowestPoint(points, 4);
        ref = points[lowestIdx];

        for(int i = 0; i < 4; i++) points[i].angle = findAngle(points[i]);

        // counter-clockwise
        qsort(points, 4, sizeof(Point), cmp);
        // for (int i = 0; i < 4; i++) printf("(%f %f)\n", points[i].x, points[i].y);
        // printf("(%f %f)\n", ref.x, ref.y);
        indx = 0;
        for(int i = 0; i < 4; i++){
            for(int j = i+1; j < 4; j++){
                sides[indx++] = dis(points[i], points[j]);
            }
        }
        // for(int i = 0; i < 6; i++) printf("%d\n", sides[i]);
        if(sides[0] == sides[2] && sides[2] == sides[3] && sides[3] == sides[5]){
            if(sides[1] == sides[4]) printf("square\n");
            else printf("diamond\n");
        }else if(sides[0] == sides[5] && sides[2] == sides[3]){
            if(sides[1] == sides[4]) printf("rectangle\n");
            else printf("other\n");
        }else{ printf("other\n"); }
    }
}
