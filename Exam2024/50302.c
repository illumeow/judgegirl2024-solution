#include <stdio.h>
#include <string.h>

int find(char* s){
    char* num[10] = {"", "yi1", "er4", "san1", "sz4", "wu3", "lyou4", "chi1", "ba1", "jyou3"};
    for(int i = 1; i < 10; i++)
        if(strcmp(s, num[i]) == 0)
            return i;
    return -1;
}

int main(){
    char s[10];
    int ans = 0, buffer1 = 0, buffer0 = 0;
    while(scanf("%s", s) != EOF){
        if(strcmp(s, "shr2") == 0){
            buffer1 += buffer0*10;
            buffer0 = 0;
        }
        else if(strcmp(s, "bai3") == 0){
            buffer1 += buffer0*100;
            buffer0 = 0;
        } 
        else if(strcmp(s, "chyan1") == 0){
            buffer1 += buffer0*1000;
            buffer0 = 0;
        }
        else if(strcmp(s, "wan4") == 0){
            buffer1 += buffer0;
            buffer0 = 0;
            ans += buffer1*10000;
            buffer1 = 0;
        }
        else if(strcmp(s, "yi4") == 0){
            buffer1 += buffer0;
            buffer0 = 0;
            ans += buffer1*100000000;
            buffer1 = 0;
        }
        else{ /* 1 ~ 9 */
            buffer0 += find(s);
        }
    }
    ans += buffer1;
    ans += buffer0;
    printf("%d\n", ans);
}