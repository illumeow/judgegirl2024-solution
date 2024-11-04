#include <stdio.h>

int evaluate_f(int *iptr[], int n, int *index){
    int max = -1e9;
    for(int i = 0; i < n; i++){
        int x = (iptr[i])[0];
        int y = (iptr[i])[1];
        int f = 4*x - 6*y;
        if(f > max){
            max = f;
            *index = i;
        }
    }
    return max;
}