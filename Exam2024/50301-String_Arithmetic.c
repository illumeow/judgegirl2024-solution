#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    n--;
    char ans[5005] = "";
    char terms[5005] = "";
    char last_operator[2] = "+";
    char operand[5005], operator[2];
    scanf("%s", terms);
    while(n--){
        scanf("%s", operator);
        scanf("%s", operand);
        if(strcmp(operator , "*") == 0){
            int termslen = strlen(terms);
            int num = atoi(operand), indx = 0;
            char tmp[5005] = "";
            for(int i = 0; i < termslen; i++){
                memset(tmp+indx, terms[i], num);
                indx += num;
            }
            tmp[indx] = '\0';
            strcpy(terms, tmp);
        }
        else if(strcmp(operator , "/") == 0){
            int termslen = strlen(terms);
            int num = atoi(operand), indx = 0;
            char tmp[5005] = "";
            for(int i = 0; i < termslen; i++){
                if(i % num == 0){
                    tmp[indx] = terms[i];
                    indx++;
                }
            }
            tmp[indx] = '\0'; 
            strcpy(terms, tmp);
        }
        else{  // +, -
            if(strcmp(last_operator , "+") == 0){
                strcat(ans, terms);
            }
            else{ // -
                int anslen = strlen(ans);
                int termslen = strlen(terms);
                if(anslen >= termslen && 
                   strcmp(terms, &(ans[anslen - termslen])) == 0)
                    ans[anslen - termslen] = '\0';
            }
            strcpy(terms, operand);
            strcpy(last_operator, operator);
        }
    }
    if(strcmp(last_operator , "+") == 0){
        strcat(ans, terms);
    }
    else{ // -
        int anslen = strlen(ans);
        int termslen = strlen(terms);
        if(anslen >= termslen && 
           strcmp(terms, &(ans[anslen - termslen])) == 0)
            ans[anslen - termslen] = '\0';
    }
    printf("%s", ans);
}