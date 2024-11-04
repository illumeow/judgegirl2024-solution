#include <stdio.h>

/*
return the one with the largest digit sum.
If there is more than one number with the largest digit sum, 
return the one with the least number of digits. 
If there is more than one number with the least number of digits, 
return the one with the largest numeric value.
*/

int digit_sum(int n){
    int sum = 0;
    while(n/10){
        sum += n % 10;
        n /= 10;
    }
    sum += n;
    return sum;
}

int digit_num(int n){
    int num = 1;
    while(n/10){
        num++;
        n /= 10;
    }
    return num;
}

int main(){
    int n, ans, ansDigitSum = -1, ansDigitNum = 1e9;
    while(scanf("%d", &n) != EOF){
        if(digit_sum(n) > ansDigitSum){
            ans = n;
            ansDigitSum = digit_sum(n);
            ansDigitNum = digit_num(n);
        }
        else if(digit_sum(n) == ansDigitSum && digit_num(n) < ansDigitNum){
            ans = n;
            ansDigitSum = digit_sum(n);
            ansDigitNum = digit_num(n);
        }
        else if(digit_sum(n) == ansDigitSum && digit_num(n) == ansDigitNum && n > ans){
            ans = n;
            ansDigitSum = digit_sum(n);
            ansDigitNum = digit_num(n);
        }
    }
    printf("%d", ans);
}