#include <stdio.h>

int main(){
    int S, C;
    scanf("%d%d", &S, &C);
    int hashtable[100000][10] = {{}};
    int lastUsed[100000] = {};  // last used index + 1 (b/c init issues)
    
    int k;
    while(scanf("%d", &k) != EOF){
        int hash = (77*k+2222) % S;
        int found = 0;
        
        // printf("row %d: last %d\n", hash, lastUsed[hash]);
        for(int i = 0; i < C; i++){
            // printf("searching %d: %d %d\n", k, hash, i);
            if(hashtable[hash][i] == k){
                found = 1;
                hashtable[hash][i] = 0;
                printf("%d %d\n", k, hash);
                break;
            }
        }
        
        if(!found){
            int i;
            for(i = 0; i < C; i++){
                if(hashtable[hash][i] == 0){
                    hashtable[hash][i] = k;
                    break;
                }
            }
        }
        #ifdef DEBUG
        printf("------------\nhash: %d, lastused: %d\n", hash, lastUsed[hash]);

        for(int m = 0; m < S; m++){
            for(int n = 0; n < C; n++){
                printf("%d ", hashtable[m][n]);
            }
            printf("\n");
        }
        printf("===================\n");
        #endif
    }
}