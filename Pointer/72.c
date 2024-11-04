/*
ptr[0] = &(arr[0]), ptr[n-1] = &(arr[-1])
*/
#include <stdlib.h>

int cmp(const void *A, const void *B){
    const int *a = A;
    const int *b = B;
    return (*a > *b) - (*a < *b);
}

void fill_array(int *ptr[], int n){
    for(int i = 0; i < n; i++) *ptr[i] = i;

    /* sort ptr */
    qsort(ptr, n, sizeof(int*), cmp);

    /* ptr[i] = the i-th element being pointed */
    for(int i = 0; i < n-1; i++){
        int *now = ptr[i];
        int num = *ptr[i] + *ptr[i+1];
        while(now < ptr[i+1] - 1){
            now++;
            *now = num;
        }
    }
}