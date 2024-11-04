#include <stdio.h>

int main(){
    int n, x, a = 0, b = 0, c = 0; 
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        if(x % 3 == 0) a++;
        else if(x % 3 == 1) b++;
        else if(x % 3 == 2) c++;
    }
    printf("%d %d %d", a, b, c);
}