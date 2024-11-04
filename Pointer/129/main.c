#include <stdio.h>
#include "prepare_array.h"
 
int main() {
    int row = 4;
    int column[4] = {10, 20, 30, 10};
    /* 0 10 30 60 */
    int *array[50];
    int buffer[10000];
    // array[0] = &(buffer[0]);
    // printf("%p\n", &(array[0]));
    // printf("%p\n", &(array[0]) + 1);
    // printf("%p\n", &(array[0])+ 5);
    // printf("%p\n", array[0]+5);
    // printf("%p\n", &(array[0][5]));
    prepare_array(buffer, array, row, column);
    for (int i = 0; i < 4; i++)
     for (int j = 0; j < column[i]; j++){
       printf("%d %d %p\n", i, j, &(array[i][j]));
       array[i][j] = i * 100 + j;
     }
    return 0;
}