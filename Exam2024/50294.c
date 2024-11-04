#include <stdio.h>
 
int main(){
    /* a > b > 0 */
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
 
    int num;
    int ucnt, uprev, umaxcnt = 0;
    int dcnt, dprev, dmaxcnt;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2*a - b; j++){
            scanf("%d", &num);
            if(j < b || (j-b)%4 == 0 || (j-b-3)%4 == 0){
                /* down */
                if(i == 0 && j == 0){
                    /* head of down */
                    dprev = num;
                    dmaxcnt = dcnt = 1;
                    #ifdef DEBUG
                    printf("d%d, head\n", num);
                    #endif
                    continue;
                }
 
                if(num == dprev){
                    dcnt++;
                }else{
                    /* new num */
                    dcnt = 1;
                }
 
                if(dmaxcnt < dcnt){
                    dmaxcnt = dcnt;
                }
 
                #ifdef DEBUG
                printf("d%d, dprev: %d, dcnt: %d, dmcnt: %d\n", num, dprev, dcnt, dmaxcnt);
                #endif
 
                dprev = num;
            }else{
                /* up */
                if(j == b+1){
                    /* head of up */
                    uprev = num;
                    ucnt = 1;
                    #ifdef DEBUG
                    printf("u%d, head of %d\n", num, i);
                    #endif
                    continue;
                }
 
                if(num == uprev){
                    ucnt++;
                }else{
                    /* new num */
                    ucnt = 1;
                }
 
                if(umaxcnt < ucnt){
                    umaxcnt = ucnt;
                }
 
                #ifdef DEBUG
                printf("u%d, uprev: %d, ucnt: %d, umcnt: %d\n", num, uprev, ucnt, umaxcnt);
                #endif
 
                uprev = num;
            }
        }
    }
    int ans = (umaxcnt > dmaxcnt)?umaxcnt:dmaxcnt;
    printf("%d", ans);
}