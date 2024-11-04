#include <stdio.h>
#define PI 3.1415926

int main(){
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double d = (c-b > 0)?c-b:0;
    double e = (c-a > 0)?c-a:0;
    printf("%f", 0.75*c*c*PI + 0.25*d*d*PI + 0.25*e*e*PI);
}