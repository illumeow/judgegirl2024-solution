#include <stdio.h>
 
int main() {
    int A, B ,C;
    scanf("%d%d%d", &A, &B, &C);
    int disk = B+C-A;
    int CPU = A+C-B;
    int GPU = A+B-C;
    printf("%d\n%d\n%d", disk/2, CPU/2, GPU/2);
    return 0;
}