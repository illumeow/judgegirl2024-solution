#include <stdio.h>

int calRectArea(int N, int M, int* ptrMat, int* ptrLeft[], int* ptrRight[]){
    /*
    map: N*N, num of rectangle: M = length of ptrLeft, ptrRight
    &mat[1][0]-&mat[0][0] = N, &mat[0][y]-&mat[0][0] = y < N
    &mat[2][0]-&mat[0][0] = 2N
    */
    int pl = ptrLeft[0] - ptrMat;
    int pr = ptrRight[0] - ptrMat;
    int x1 = pl / N, y1 = pl % N;
    int x2 = pr / N, y2 = pr % N;
    int prevx2 = x2, prevy2 = y2;
    int sum = (x2-x1+1)*(y2-y1+1);
    for(int i = 1; i < M; i++){
        pl = ptrLeft[i] - ptrMat;
        pr = ptrRight[i] - ptrMat;
        int x1 = pl / N, y1 = pl % N;
        int x2 = pr / N, y2 = pr % N;
        sum += (x2-x1+1)*(y2-y1+1);
        sum -= (prevx2-x1+1)*(prevy2-y1+1);
        prevx2 = x2, prevy2 = y2;
    }
    return sum;
}