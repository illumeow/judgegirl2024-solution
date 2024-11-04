#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void mergeString(char** P, char L[26], char* A){
    // P[i] is a string and P ends with a NULL
    // maxPn = 200, maxP[i]len = 200
    int ai = 0;
    for(;;){
        int i = 0, min = 30, smallesti = -1;
        while(P[i] != NULL){
            if(*P[i] == '\0'){
                i++;
                continue;
            }
            if((strchr(L, *P[i]) - L) < min){
                min = strchr(L, *P[i]) - L;
                smallesti = i;
            }
            i++;
        }
        if(smallesti == -1) break;
        A[ai++] = *P[smallesti];
        P[smallesti]++;
    }
}