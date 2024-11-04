#include <stdio.h>

int main(){
    char c;
    int ans = 0, flag = 1;
    for(;;){
        if(flag) c = getchar();
        if(c == EOF) break;
        if(c == '.'){
            c = getchar();
            if(c == '\n') ans++;
            else if(c == EOF){
                ans++;
                break;
            }
            else if(c == ' '){
                c = getchar();
                ans += (c == ' ');
            }
            else if(c == '.'){
                flag = 0;
                continue;
            }
        }
        flag = 1;
    }
    printf("%d", ans);
}