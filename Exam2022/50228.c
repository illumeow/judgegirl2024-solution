#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int prev, diff = 1e9;
    int sum, cnt, head;
    int asum, acnt, ahead;
    asum = acnt = ahead = -1;
    int num;

    scanf("%d", &num);
    prev = head = sum = num;
    cnt = 1;

    for(int i = 1; i < n; i++){
        scanf("%d", &num);
        if(num - prev == diff){
            cnt++;
            sum += num;
            prev = num;
            continue;
        }
        if(sum > asum || (sum == asum && cnt > acnt) 
        || (sum == asum && cnt == acnt && head > ahead)){
            asum = sum;
            acnt = cnt;
            ahead = head;
        }
        diff = num - prev;
        sum = prev + num;
        cnt = 2;
        head = prev;

        prev = num;
    }

    if(sum > asum || (sum == asum && cnt > acnt) 
    || (sum == asum && cnt == acnt && head > ahead)){
        asum = sum;
        acnt = cnt;
        ahead = head;
    }

    printf("%d %d %d", asum, acnt, ahead);
}