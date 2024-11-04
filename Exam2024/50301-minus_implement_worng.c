#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    n--;
    char ans[5005] = "";
    char product[5005] = "";
    char last_operator[2] = "+";
    char operand[5005], operator[2];
    scanf("%s", product);
    while(n--){
        scanf("%s", operator);
        scanf("%s", operand);
        if(strcmp(operator , "*") == 0){
            int len = strlen(product);
            int num = atoi(operand), indx = 0;
            char tmp[5005] = "";
            for(int i = 0; i < len; i++){
                memset(tmp+indx, product[i], num);
                indx += num;
            }
            tmp[indx] = '\0'; 
            strcpy(product, tmp);
        }
        else if(strcmp(operator , "/") == 0){
            int len = strlen(product);
            int num = atoi(operand), indx = 0;
            char tmp[5005] = "";
            for(int i = 0; i < len; i++){
                if(i % num == 0){
                    tmp[indx] = product[i];
                    indx++;
                }
            }
            tmp[indx] = '\0'; 
            strcpy(product, tmp);
        }
        else{  // +, -
            if(strcmp(last_operator , "+") == 0){
                strcat(ans, product);
            }
            else{ // -
                /*
                if
                ans = "abcdefdef"
                product = "def"
                then this won't work
                (strlen(p) = 6)
                */
                char *p = strstr(ans, product);
                if(p != NULL && strlen(p) == strlen(product)){
                    *p = '\0';
                }
            }
            strcpy(product, operand);
            strcpy(last_operator, operator);
        }
        #ifdef DEBUG
        printf("n= %d, op = %s%s\n", n, operator, operand);
        printf("product = %s, ans = %s\n", product, ans);
        #endif
    }
    if(strcmp(last_operator , "+") == 0){
        strcat(ans, product);
    }
    else{ // -
        char *p = strstr(ans, product);
        if(p != NULL && strlen(p) == strlen(product)){
            *p = '\0';
        }
    }
    printf("%s", ans);
}