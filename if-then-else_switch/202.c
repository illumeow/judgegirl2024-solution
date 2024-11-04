#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b){
    if (a == 0) return b;
    if (b == 0) return a;

    if (a == b) return a;

    if (a > b) return gcd(a-b, b);
    return gcd(a, b-a);
}

int main(){
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
    int h=0, i=0, j=0, flag=0, k=0;
    int x = (a>0)?a*c+b:a*c-b, y = (e>0)?e*g+f:e*g-f;

    if((d == 0)||(d == 1)){
        // add
        if(d == 0){
            i = x*g+y*c;
            j = c*g;
        // sub
        }else{
            i = x*g-y*c;
            j = c*g;
        }
        
        // improper to mixed
        k = gcd(abs(i), abs(j));
        i /= k;
        j /= k;
        // printf("i: %d; j: %d\n", i, j);
        if(i*j < 0) flag = 1;
        
        i = abs(i);
        j = abs(j);
        while(i>=j){
            i -= j;
            h++;
        }
        if(i == 0) j = 1;

        if(flag == 1) h = -h;
    }else if((d == 2)||(d == 3)){
        // mul
        if(d == 2){
            i = x*y;
            j = c*g;
        // div
        }else{
            i = x*g;
            j = c*y;
        }
        // improper to mixed
        k = gcd(abs(i), abs(j));
        i /= k;
        j /= k;
        if(i*j < 0) flag = 1;
        
        i = abs(i);
        j = abs(j);
        while(i>=j){
            i -= j;
            h++;
        }
        if(i == 0) j = 1;

        if(flag == 1) h = -h;
    }

    printf("%d\n%d\n%d", h, i, j);
}
