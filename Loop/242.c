#include <stdio.h>
#define ll long long

int tx[2000], ty[2000], ti;

int tested(int x, int y){
    for(int i = 0; i < ti; i++){
        if(x == tx[i] && y == ty[i]) return 1;
    }
    return 0;
}

int in_circle(ll int x, ll int y, ll int cx, ll int cy, ll int r){
    return((x-cx)*(x-cx)+(y-cy)*(y-cy) <= r*r);
}

int main(){
    int n;
    scanf("%d", &n);

    ll int x1, y1, r1, x2, y2, r2, x3, y3, r3;
    int count;
    while(n--){
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &x1, &y1, &r1, &x2, &y2, &r2, &x3, &y3, &r3);
        
        count = 0;
        ti = 0;
        #ifdef DEBUG
        printf("circle 1\n");
        #endif
        for(ll int i = x1-r1; i <= x1+r1; i++){
            for(ll int j = y1-r1; j <= y1+r1; j++){
                if(!tested(i, j) && (
                   (in_circle(i, j, x1, y1, r1) && in_circle(i, j, x2, y2, r2) && in_circle(i, j, x3, y3, r3)) ||
                   (in_circle(i, j, x1, y1, r1) && !in_circle(i, j, x2, y2, r2) && !in_circle(i, j, x3, y3, r3)) ||
                   (!in_circle(i, j, x1, y1, r1) && in_circle(i, j, x2, y2, r2) && !in_circle(i, j, x3, y3, r3)) ||
                   (!in_circle(i, j, x1, y1, r1) && !in_circle(i, j, x2, y2, r2) && in_circle(i, j, x3, y3, r3)))){
                    count++;
                    #ifdef DEBUG
                    printf("(%d, %d)\n", i, j);
                    #endif
                   }
                tx[ti] = i;
                ty[ti] = j;
                ti++;
            }
        }
        #ifdef DEBUG
        printf("visited:\n");
        for(int i = 0; i < ti; i++) printf("(%d, %d)\n", tx[i], ty[i]);
        printf("circle 2\n");
        #endif
        for(ll int i = x2-r2; i <= x2+r2; i++){
            for(ll int j = y2-r2; j <= y2+r2; j++){
                if(!tested(i, j) && (
                   (in_circle(i, j, x1, y1, r1) && in_circle(i, j, x2, y2, r2) && in_circle(i, j, x3, y3, r3)) ||
                   (in_circle(i, j, x1, y1, r1) && !in_circle(i, j, x2, y2, r2) && !in_circle(i, j, x3, y3, r3)) ||
                   (!in_circle(i, j, x1, y1, r1) && in_circle(i, j, x2, y2, r2) && !in_circle(i, j, x3, y3, r3)) ||
                   (!in_circle(i, j, x1, y1, r1) && !in_circle(i, j, x2, y2, r2) && in_circle(i, j, x3, y3, r3)))){
                    count++;
                    #ifdef DEBUG
                    printf("(%d, %d)\n", i, j);
                    #endif
                   }
                tx[ti] = i;
                ty[ti] = j;
                ti++;
            }
        }
        #ifdef DEBUG
        printf("visited:\n");
        for(int i = 0; i < ti; i++) printf("(%d, %d)\n", tx[i], ty[i]);
        printf("circle 3\n");
        #endif
        for(ll int i = x3-r3; i <= x3+r3; i++){
            for(ll int j = y3-r3; j <= y3+r3; j++){
                if(!tested(i, j) && (
                   (in_circle(i, j, x1, y1, r1) && in_circle(i, j, x2, y2, r2) && in_circle(i, j, x3, y3, r3)) ||
                   (in_circle(i, j, x1, y1, r1) && !in_circle(i, j, x2, y2, r2) && !in_circle(i, j, x3, y3, r3)) ||
                   (!in_circle(i, j, x1, y1, r1) && in_circle(i, j, x2, y2, r2) && !in_circle(i, j, x3, y3, r3)) ||
                   (!in_circle(i, j, x1, y1, r1) && !in_circle(i, j, x2, y2, r2) && in_circle(i, j, x3, y3, r3)))){
                    count++;
                    #ifdef DEBUG
                    printf("(%d, %d)\n", i, j);
                    #endif
                   }
                tx[ti] = i;
                ty[ti] = j;
                ti++;
            }
        }
        printf("%d\n", count);
    }
}