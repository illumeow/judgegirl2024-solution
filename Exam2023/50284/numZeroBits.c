#include "numZeroBits.h"
#include <stdint.h>

int numZeroBits(GiantUnsignedInt *giantNum){
    int max = 0, now = 0;
    for(int i = giantNum->n - 1; i >= 0; i--){
        uint64_t n = giantNum->array[i];
        for(int j = 0; j < 64; j++){
            if(n & 1){
                max = (max > now)? max: now;
                now = 0;
            }
            else now++;
            n >>= 1;
        }
    }
    max = (max > now)? max: now;
    return max;
}