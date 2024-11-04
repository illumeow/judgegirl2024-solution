#include <stdio.h>
#include <stdint.h>
 
 
int main(){
    int n;  // 1 < n <= 75000
    scanf("%d", &n);
    uint64_t grid[75005];
    for(int i = 0; i < 75000; i++){
        scanf("%lu", &(grid[i]));
    }
 
    // row
    int row = 0;
    for(int i = 0; i < 75000; i++){
        uint64_t num = grid[i];
        int cnt = 0;
        for(int j = 0; j < 64; j++){
            if(num & 1) cnt++;
            else{
                if(cnt >= n) row += cnt-n+1;
                cnt = 0;
            }
            num >>= 1;
        }
        if(cnt >= n) row += cnt-n+1;
    }
    printf("%d\n", row);
 
    // column
    int col = 0;
    for(int i = 0; i < 64; i++){
        uint64_t mask = 1ULL << i;
        int cnt = 0;
        for(int j = 0; j < 75000; j++){
            if(grid[j] & mask) cnt++;
            else{
                if(cnt >= n) col += cnt-n+1;
                cnt = 0;
            }
        }
        if(cnt >= n) col += cnt-n+1;
    }
    printf("%d\n", col);
 
    // main diag
    int mdiag = 0;
    for(int i = 0; i < 63; i++){
        int cnt = 0;
        for(int j = 0; j <= i; j++){
            uint64_t mask = 1ULL << (i-j);
            if(grid[j] & mask) cnt++;
            else{
                if(cnt >= n) mdiag += cnt-n+1;
                cnt = 0;
            }
        }
        if(cnt >= n) mdiag += cnt-n+1;
    }
    for(int i = 0; i < 74937; i++){
        int cnt = 0;
        for(int j = 0; j < 64; j++){
            uint64_t mask = 1ULL << (63-j);
            if(grid[i+j] & mask) cnt++;
            else{
                if(cnt >= n) mdiag += cnt-n+1;
                cnt = 0;
            }
        }
        if(cnt >= n) mdiag += cnt-n+1;
    }
    for(int i = 74937; i < 75000; i++){
        int cnt = 0;
        for(int j = i; j < 75000; j++){
            uint64_t mask = 1ULL << (63-(j-i));
            if(grid[j] & mask) cnt++;
            else{
                if(cnt >= n) mdiag += cnt-n+1;
                cnt = 0;
            }
        }
        if(cnt >= n) mdiag += cnt-n+1;
    }
    printf("%d\n", mdiag);
 
    // anti diag
    int adiag = 0;
    for(int i = 0; i < 63; i++){
        int cnt = 0;
        for(int j = 0; j <= i; j++){
            uint64_t mask = 1ULL << (63-(i-j));
            if(grid[j] & mask) cnt++;
            else{
                if(cnt >= n) adiag += cnt-n+1;
                cnt = 0;
            }
        }
        if(cnt >= n) adiag += cnt-n+1;
    }
    for(int i = 0; i < 74937; i++){
        int cnt = 0;
        for(int j = 0; j < 64; j++){
            uint64_t mask = 1ULL << j;
            if(grid[i+j] & mask) cnt++;
            else{
                if(cnt >= n) adiag += cnt-n+1;
                cnt = 0;
            }
        }
        if(cnt >= n) adiag += cnt-n+1;
    }
    for(int i = 74937; i < 75000; i++){
        int cnt = 0;
        for(int j = i; j < 75000; j++){
            uint64_t mask = 1ULL << (j-i);
            if(grid[j] & mask) cnt++;
            else{
                if(cnt >= n) adiag += cnt-n+1;
                cnt = 0;
            }
        }
        if(cnt >= n) adiag += cnt-n+1;
    }
    printf("%d\n", adiag);
}