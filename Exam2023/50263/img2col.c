#include "image2column.h"

void img2col(int h, int w, int k, int imgMatrix[MAXH][MAXW], int colMatrix[MAXK * MAXK][MAXW * MAXH]){
    int colj = -1;
    for(int i = 0; i < h-k+1 ; i++){
        for(int j = 0; j < w-k+1; j++){
            colj++;
            int coli = 0;
            /* from (i, j) get a k*k window */
            for(int r = i; r < i+k; r++){
                for(int c = j; c < j+k; c++){
                    colMatrix[coli++][colj] = imgMatrix[r][c];
                }
            }
        }
    }
}