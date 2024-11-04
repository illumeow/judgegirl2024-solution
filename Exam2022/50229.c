#include <stdio.h>

int main(){
    int k;
    scanf("%d", &k);
    int capacity[20005] = {};
    for(int i = 0; i < k; i++)
        scanf("%d", &(capacity[i]));
    int water[20005] = {};
    for(int i = 0; i < k; i++)
        scanf("%d", &(water[i]));

    int i, j;
    while(scanf("%d%d", &i, &j) != EOF){
        if(i == k) water[j] = capacity[j];
        else if(j == k) water[i] = 0;
        else{
            if(water[i] >= capacity[j]-water[j]){
                water[i] -= capacity[j]-water[j];
                water[j] = capacity[j];
            }else{
                water[j] += water[i];
                water[i] = 0;
            }
        }
    }
    
    for(int i = 0; i < k-1; i++)
        printf("%d ", water[i]);
    printf("%d", water[k-1]);
}