#include <stdio.h>
#define max(a,b) ((a>b)?a:b)

int main() {
    int n;
    scanf("%d", &n);
    int x1, y1, x2, y2, x3, y3;
    int A, B, C, M;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
        A = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        B = (x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
        C = (x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
        M = max(A, B);
        M = max(C, M);
        // printf("%d %d %d %d\n", A, B, C, M);
        if((A == B)||(B == C)||(C == A)) {
            printf("isosceles\n");
            continue;
        }
        if(M == A) {
            if(B+C > A) {
                printf("acute\n");
            }else if(B+C < A) {
                printf("obtuse\n");
            }else{
                printf("right\n");
            }
        }else if (M == B) {
            if(A+C > B) {
                printf("acute\n");
            }else if(A+C < B) {
                printf("obtuse\n");
            }else{
                printf("right\n");
            }
        }else{
            if(A+B > C) {
                printf("acute\n");
            }else if(A+B < C) {
                printf("obtuse\n");
            }else{
                printf("right\n");
            }
        }
    }
}
