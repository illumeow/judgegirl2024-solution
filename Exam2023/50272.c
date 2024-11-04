#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void num2word(char *s, char* ret){
    char *num[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *ty[] = {"", "", "twenty-", "thirty-", "forty-", "fifty-", "sixty-", "seventy-", "eighty-", "ninety-"};
    int digit = strlen(s);
    int cnt = 0;

    if(digit == 3){
        strcat(ret, num[s[cnt] - '0']);
        strcat(ret, " hundred ");
        cnt++;
    }
    int n = atoi(s+cnt);
    if(n < 20){
        strcat(ret, num[n]);
    }else{
        strcat(ret, ty[s[cnt] - '0']);
        strcat(ret, num[s[cnt+1] - '0']);
    }
}

int main(){
    char *words[] = {"", " thousand ", " million ", " billion ", " trillion ", " quadrillion ", " quintillion "};
    char longnumber[20];
    scanf("%s", longnumber);
    int digit = strlen(longnumber);
    char *head = longnumber;
    // printf("%d", digit);
    int comma = (digit-1)/3;
    char strnum[4] = {}, num[25] = {};
    strncpy(strnum, head, digit-comma*3);
    head += digit-comma*3;
    num2word(strnum, num);
    printf("%s", num);
    for(int i = 0; comma > 0; i++, comma--){
        printf("%s", words[comma]);
        strncpy(strnum, head, 3);
        strnum[3] = '\0';
        head += 3;
        num[0] = '\0';
        num2word(strnum, num);
        printf("%s", num);
    }
}