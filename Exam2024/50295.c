#include <stdio.h>

int main(){
    int m, C;
    scanf("%d%d", &m, &C);
    int size[1000];
    for(int i = 0; i < m; i++)
        scanf("%d", &(size[i]));
    
    int cnt = 0;

    /* best-fit */
    int bin1[1000] = {};
    for(int i = 0; i < m; i++){
        int min = 1e9;
        int index = -1;
        for(int j = 0; j < cnt; j++){
            if(C - bin1[j] < min && C - bin1[j] >= size[i]){
                index = j;
                min = C - bin1[j];
            }
        }

        if(index == -1){
            bin1[cnt] = size[i];
            cnt++;
            #ifdef DEBUG1
            for(int i = 0; i < cnt; i++)
                printf("%d ", bin1[i]);
            printf("\n");
            #endif
            continue;
        }

        bin1[index] += size[i];

        #ifdef DEBUG1
        for(int i = 0; i < cnt; i++)
            printf("%d ", bin1[i]);
        printf("\n");
        #endif
    }

    printf("%d ", cnt); 
    
    cnt = 0;

    /* first-fit */
    int bin2[1000] = {};
    for(int i = 0; i < m; i++){
        int index = -1;
        for(int j = 0; j < cnt; j++){
            if(C - bin2[j] >= size[i]){
                index = j;
                break;
            }
        }

        if(index == -1){
            bin2[cnt] = size[i];
            cnt++;
            #ifdef DEBUG2
            for(int i = 0; i < cnt; i++)
                printf("%d ", bin2[i]);
            printf("\n");
            #endif
            continue;
        }

        bin2[index] += size[i];

        #ifdef DEBUG2
        for(int i = 0; i < cnt; i++)
            printf("%d ", bin2[i]);
        printf("\n");
        #endif
    }

    printf("%d ", cnt); 
    
    cnt = 0;

    /* worst-fit */
    int bin3[1000] = {};
    for(int i = 0; i < m; i++){
        int max = -1e9;
        int index = -1;
        for(int j = 0; j < cnt; j++){
            if(C - bin3[j] > max && C - bin3[j] >= size[i]){
                index = j;
                max = C - bin3[j];
            }
        }

        if(index == -1){
            bin3[cnt] = size[i];
            cnt++;
            #ifdef DEBUG1
            for(int i = 0; i < cnt; i++)
                printf("%d ", bin3[i]);
            printf("\n");
            #endif
            continue;
        }

        bin3[index] += size[i];

        #ifdef DEBUG1
        for(int i = 0; i < cnt; i++)
            printf("%d ", bin3[i]);
        printf("\n");
        #endif
    }

    printf("%d", cnt); 
}