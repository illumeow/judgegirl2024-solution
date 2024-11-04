/* If the type is 79, then the metal is gold. 
The rest are 47,29,82,26,22, for silver, copper, lead, iron, and titanium.
The unit price of these metals are 30,10,4,5,3,9 respectively. */

#include "value.h"

int gcd(int a, int b){
    int i = (a>b)?a:b;
    int j = (a>b)?b:a;
    while(i % j != 0){
        int r = i % j;
        i = j;
        j = r;
    }
    return j;
}

int value(int type, int width, int height, int length) {
    int p;
    switch(type) {
        case 79: p = 30; break;
        case 47: p = 10; break;
        case 29: p = 4; break;
        case 82: p = 5; break;
        case 26: p = 3; break;
        case 22: p = 9; break;
        default: return -1;
    }
    if(width <= 0 || height <= 0 || length <= 0) return -2;
    int k = gcd(width, gcd(height, length));
    return k*k*k*width*height*length*p;
}