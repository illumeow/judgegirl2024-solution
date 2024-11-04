#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n;  // the number of operands
    scanf("%d", &n);
    n--;
    char ans[5005];
    scanf("%s", ans);
    bool flag = true;
    while(n > 0){
        char operator[2];
        char s[5005];
        if(flag)
            scanf("%s%s", operator, s);
        flag = true;
        // printf("out, n = %d, %s: %s\n", n, operator, s);
        if(strcmp(operator , "+") == 0){
            char tmpans[5005];
            strcpy(tmpans, s);
            while(n-1 > 0){
                char tmpoperator[2];
                char tmps[5005];
                scanf("%s%s", tmpoperator, tmps);
                // printf("+, n = %d, %s: %s\n", n-1, tmpoperator, tmps);
                if(strcmp(tmpoperator , "*") == 0){
                    int len = strlen(tmpans);
                    int slen = atoi(tmps), indx = 0;
                    char tmp[5005] = "";
                    for(int i = 0; i < len; i++){
                        memset(tmp+indx, tmpans[i], slen);
                        indx += slen;
                    }
                    tmp[indx] = '\0'; 
                    strcpy(tmpans, tmp);
                }
                else if(strcmp(tmpoperator , "/") == 0){
                    int len = strlen(tmpans);
                    int slen = atoi(tmps), indx = 0;
                    char tmp[5005] = "";
                    for(int i = 0; i < len; i++){
                        if(i % slen == 0){
                            tmp[indx] = tmpans[i];
                            indx++;
                        }
                    }
                    tmp[indx] = '\0'; 
                    strcpy(tmpans, tmp);
                }
                else{
                    strcat(ans, tmpans);
                    strcpy(operator, tmpoperator);
                    strcpy(s, tmps);
                    flag = false;
                    break;
                }
                n--;
                // printf("%s\n", tmpans);
                if(n-1 == 0){
                    strcat(ans, tmpans);
                }
            }
        }
        else if(strcmp(operator , "-") == 0){
            char tmpans[5005];
            strcpy(tmpans, s);
            while(n-1 > 0){
                char tmpoperator[2];
                char tmps[5005];
                scanf("%s%s", tmpoperator, tmps);
                // printf("-, n = %d, %s: %s\n", n-1, tmpoperator, tmps);
                if(strcmp(tmpoperator , "*") == 0){
                    int len = strlen(tmpans);
                    int n = atoi(tmps), indx = 0;
                    char tmp[5005] = "";
                    for(int i = 0; i < len; i++){
                        memset(tmp+indx, tmpans[i], n);
                        indx += n;
                    }
                    tmp[indx] = '\0'; 
                    strcpy(tmpans, tmp);
                }
                else if(strcmp(tmpoperator , "/") == 0){
                    int len = strlen(tmpans);
                    int n = atoi(tmps), indx = 0;
                    char tmp[5005] = "";
                    for(int i = 0; i < len; i++){
                        if(i % n == 0){
                            tmp[indx] = tmpans[i];
                            indx++;
                        }
                    }
                    tmp[indx] = '\0'; 
                    strcpy(tmpans, tmp);
                }
                else{
                    int sumlen = strlen(ans);
                    int termslen = strlen(tmpans);
                    if(sumlen >= termslen && strcmp(tmpans, &(ans[sumlen - termslen])) == 0){
                        ans[sumlen - termslen] = '\0';
                    }
                    strcpy(operator, tmpoperator);
                    strcpy(s, tmps);
                    flag = false;
                    break;
                }
                // printf("%s\n", tmpans);
                n--;
                if(n-1 == 0){
                    int sumlen = strlen(ans);
                    int termslen = strlen(tmpans);
                    if(sumlen >= termslen && strcmp(tmpans, &(ans[sumlen - termslen])) == 0){
                        ans[sumlen - termslen] = '\0';
                    }
                }
            }
        }
        else if(strcmp(operator , "*") == 0){
            int len = strlen(ans);
            int slen = atoi(s), indx = 0;
            char tmp[5005] = "";
            for(int i = 0; i < len; i++){
                memset(tmp+indx, ans[i], slen);
                indx += slen;
            }
            tmp[indx] = '\0'; 
            strcpy(ans, tmp);
        }
        else{  // operator = "/"
            int len = strlen(ans);
            int slen = atoi(s), indx = 0;
            char tmp[5005] = "";
            for(int i = 0; i < len; i++){
                if(i % slen == 0){
                    tmp[indx] = ans[i];
                    indx++;
                }
            }
            tmp[indx] = '\0'; 
            strcpy(ans, tmp);
        }
        n--;
        // printf("%s\n", ans);
    }
    printf("%s\n", ans);
}