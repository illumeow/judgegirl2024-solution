#include "numBitChanges.h"
#include <stdint.h>

int numBitChanges(GiantUnsignedInt *giantNum){
    int prev, last;
    prev = last = (giantNum->array[giantNum->n - 1] & 1);
    int cnt = 0;
    for(int i = giantNum->n - 1; i >= 0; i--){
        uint64_t n = giantNum->array[i];
        for(int j = 0; j < 64; j++){
            if((n & 1) != prev){
                cnt++;
                prev = n & 1;
            }
            n >>= 1;
        }
    }
    cnt += (prev != last);
    return cnt;
}