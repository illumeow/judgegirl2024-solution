#include <stdio.h>

void snake(int* first_element, int n, int* pointers[], int m){
    int *prev;
    int prevx, prevy;
    for(int i = 0; i < m && pointers[i] != NULL; i++){
        int x = (pointers[i]-first_element) / n;
        int y = (pointers[i]-first_element) % n;

        if(x < 0 || x >= n || y < 0 || y >= n) return;

        if(i == 0){
            prev = pointers[i];
            prevx = x;
            prevy = y;
            continue;
        }

        int sign = (pointers[i]-prev > 0)?1:-1;
        int step = 0;

        if(prevx == x)
            step = 1;
        else if(prevy == y)
            step = n;
        else if(prevx+prevy == x+y)
            step = n-1;
        else if(prevx-prevy == x-y)
            step = n+1;
        else return;
        
        while(prev != pointers[i]){
            *prev = 1;
            prev += sign*step;
        }
        *prev = 1;
        
        prevx = x, prevy = y;
    }
}