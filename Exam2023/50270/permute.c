#define MAX 1000
#include <stdio.h>

void permute(int *ptrArray[MAX], int *ptrPerms[MAX]){
    int *nowptr[MAX];
    for(int i = 0; ptrPerms[i] != NULL; i++){
        for(int j = 0; ptrArray[j] != NULL; j++)
            nowptr[j] = ptrArray[j];
        for(int j = 0; ptrArray[j] != NULL; j++){
            ptrArray[j] = nowptr[ptrPerms[i][j]];
        }
    }
}