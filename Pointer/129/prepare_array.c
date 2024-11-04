#include <stdio.h>

void prepare_array(int buffer[], int *array[], int row, int column[]){
    /* 
    "array" is an array of int arrays
    (array[row])[col]
    */
    array[0] = &(buffer[0]);
    int index = 0;
    for(int i = 0; i < row; i++){
        array[i] = &(buffer[index]);
        index += column[i];
    }
}