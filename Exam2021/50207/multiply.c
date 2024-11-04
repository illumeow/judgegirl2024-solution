#include <stdio.h>
# define ROW 3
# define COL 5
 
void multiplyMatrix(void ** arrayA, void ** arrayB, void ** arrayC){
    /*
    arrayA/B/C points to a pointer array
    in which each array element points to a 2d-matrix RxC/CxR/RxR,
    that is, each element is a 2d-array pointer (int(*)[MAXN]),
    and the pointer array ends with a NULL.
    arrarA[0] = &(matrixA[0]) = matrixA
    a = &(a[0])
    */
    int index = 0;
    while(arrayA[index] != NULL){

        int (*arrA)[COL] = (int(*)[COL])arrayA[index];
        int (*arrB)[ROW] = (int(*)[ROW])arrayB[index];
        int (*arrC)[ROW] = (int(*)[ROW])arrayC[index];

        for(int i = 0; i < ROW; i++)
            for(int j = 0; j < ROW; j++){
                arrC[i][j] = 0;
                for(int k = 0; k < COL; k++){
                    arrC[i][j] += arrA[i][k]*arrB[k][j];
                }
            }
        index++;
    }
}