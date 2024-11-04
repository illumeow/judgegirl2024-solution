#include <stdio.h>

/*
min: 10
10 -> 1, 2, 3, 4 
11 -> 1, 2, 3, 5 
12 -> 1, 2, 3, 6 | 1, 2, 4, 5
13 -> 1, 2, 3, 7 | 1, 2, 4, 6 | 1, 3, 4, 5
14 -> 1, 2, 3, 8 | 1, 2, 4, 7 | 1, 2, 5, 6 | 1, 3, 4, 5 | 2, 3, 4, 5
15 -> (0, 0, 0, 5) | (0, 0, 1, 4) | (0, 0, 2, 3) | (0, 1, 1, 3) | (0, 1, 2, 2) | (1, 1, 1, 2)
*/

int pow(int n, int p){
    int ret = 1;
    while(p--) ret *= n;
    return ret;
}

int main(){
    int s[5];
    scanf("%d %d %d %d", &s[1], &s[2], &s[3], &s[4]);
    
    for(int d = 1; d < s[1]/4; d++){
        for(int c = d+1; c+d < s[1]/2; c++){
            for(int b = c+1, a = s[1]-b-c-d; a > b; b++, a--){
                if(pow(a,2)+pow(b,2)+pow(c,2)+pow(d,2) == s[2]
                && pow(a,3)+pow(b,3)+pow(c,3)+pow(d,3) == s[3]
                && pow(a,4)+pow(b,4)+pow(c,4)+pow(d,4) == s[4]){
                    printf("%d\n%d\n%d\n%d", a, b, c, d);
                    return 0;
                }
            }
        }
    }
    printf("-1");
}