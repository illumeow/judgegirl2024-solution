#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int prev = n;
    int prevSign = (1)*(prev > 0) + (-1)*(prev < 0);
    int cnt = 1;
    while(scanf("%d", &n) != EOF){
        int nSign = (1)*(n > 0) + (-1)*(n < 0);
        if(prevSign == nSign) cnt++;
        else{
            cnt = cnt*(prevSign > 0) + (-cnt)*(prevSign < 0);
            printf("%d ", cnt);
            cnt = 1;
        }
        prevSign = nSign;
    }
    cnt = cnt*(prevSign > 0) + (-cnt)*(prevSign < 0);
    printf("%d", cnt);
}