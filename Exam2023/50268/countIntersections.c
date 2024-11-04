#define MAX_PTR_ARR_SIZE 1000
#include <stdio.h>

int countIntersections(int* ptrArray[]){
    int ret = 0;
    for(int i = 0; ptrArray[i+1] != NULL; i++)
        for(int j = i+1; ptrArray[j] != NULL; j++)
            if(ptrArray[i] > ptrArray[j]) ret++;
    return ret;
}