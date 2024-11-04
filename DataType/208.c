#include <stdio.h>

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    char c1[2], c0[2];
    scanf("%s%s", c1, c0);
    unsigned int num;
    unsigned int b = 1u << 31;
    int x = 1, y = 1;
    while(scanf("%u", &num) != EOF){
        for(int i = 0; i < 32 && !(x == 1 && y == n+1); i++){
            if(num & b) printf("%s", c1);
            else printf("%s", c0);
            num <<= 1;
            if(x == m){
                printf("\n");
                y++;
                x = 0;
            }
            x++;
        }
    }
}