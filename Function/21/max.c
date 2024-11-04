#include "max.h"

int max(int array[5][5]) {
    int ret = -1e9;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            ret = (ret > array[i][j])?ret:array[i][j];
        }
    }
    return ret;
}