#include <stdio.h>

int main(){
    /*
     1  2  3  4  5  6
     7 11 12 13 14 15
     8 16 19 20 21 22
     9 17 23 25 26 27
    10 18 24 28 29 30

     1  2  3  4  5
     6 12 13 14 15
     7 16 21 22 23
     8 17 24 28 29
     9 18 25 30 33
    10 19 26 31 34
    11 20 27 32 35
    */

    int N, M, k;
    scanf("%d%d%d", &N, &M, &k);

    int i = 1, cnt = 1, head = 1;
    while(head <= k){
        cnt++;
        head += M+N-i;
        i += 2;
    }
    // i = 2*cnt - 1
    cnt--;
    i -= 2;
    head -= M+N-i;
    // printf("head: %d, cnt: %d, i: %d\n", head, cnt, i);
    /* 
    head: the num of head of the L
    cnt: k is in the cnt-th L (from top left)
    the position of head = (cnt, cnt)
    */
    int x = cnt, y = cnt;
    if(k-head > M-cnt){
        // go down
        x += (k-head)-(M-cnt);
    }else{
        // go right
        y += k-head;
    }
    printf("%d %d", x, y);
}