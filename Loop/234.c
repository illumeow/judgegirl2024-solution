#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    const int *A = a, *B = b;
    return ((*A > *B) - (*B > *A));
}

int main(){
    long long int a, b, c, ans[3] = {};
    int indx = 0;
    scanf("%lld%lld%lld", &a, &b, &c);
    for(long long int i = 100000; i > -100001 && indx < 3; i--){
        if((i*i*i + a*i*i + b*i + c) == 0){
#ifdef DEBUG
            printf("%d %lld\n", indx, i);
            printf("%lld %lld %lld\n", ans[0], ans[1], ans[2]);
#endif
            ans[indx] = -i;
            indx++;
        }
    }
    // printf("%d\n", indx);
    switch(indx){
        case 3: break;
        case 2:
            ans[2] = a - ans[0] - ans[1];
            break;
        case 1:
            ans[1] = ans[0];
            ans[2] = ans[0];
            break;
        default:
            printf("error\n");
    }
    qsort(ans, 3, sizeof(long long int), cmp);
    printf("%lld %lld %lld\n", ans[0], ans[1], ans[2]);
}