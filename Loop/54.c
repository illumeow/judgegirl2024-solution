#include <stdio.h>

int main(){
    int N, M, ans = 0;
    scanf("%d%d", &N, &M);
    
    // int to array
    int numArray[7];
    int cnt = 6;
    while(M != 0){
        numArray[cnt] = M % 10;
        M /= 10;
        cnt--;
    }
    // for(int i = 0; i < 7; i++) printf("%d\n", numArray[i]);
    for(int i = 0; i < 6; i++) if(N == numArray[i]*10+numArray[i+1]) ans++;
    printf("%d", ans);
}