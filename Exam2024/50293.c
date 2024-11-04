#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int sum = 0, num = 0, cnt = 0, input;

    scanf("%d", &input);
    sum += input;
    num = input;
    cnt++;

    int fsum = -1, fnum, fcnt;
    int hsum = sum, hnum = num, hcnt = cnt;

    for(int i = 2; i <= n; i++){
        scanf("%d", &input);
        if(input == num){
            sum += input;
            cnt++;
        }else{
            if(sum > fsum || (sum == fsum && num < fnum)){
                if(fsum == -1){
                    hsum = sum;
                    hcnt = cnt;
                }
                fsum = sum;
                fnum = num;
                fcnt = cnt;
            }
            sum = input;
            num = input;
            cnt = 1;
        }
    }

    if(num == hnum && cnt != n){
        sum += hsum;
        cnt += hcnt;
    }
    if(sum > fsum || (sum == fsum && num < fnum)){
        fnum = num;
        fcnt = cnt;
    }
    #ifdef DEBUG
    printf("sum: %d num: %d cnt: %d\nfsum: %d fnum: %d fcnt: %d\nhsum: %d hnum: %d hcnt: %d\n", sum, num, cnt, fsum, fnum, fcnt, hsum, hnum, hcnt);
    #endif
    printf("%d %d", fnum, fcnt);
}