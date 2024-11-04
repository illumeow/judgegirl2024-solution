#include <stdio.h>
#include <string.h>

int main(){
    char head[1005], prev[1005], now[1005];
    scanf("%s", head);
    scanf("%s", now);
    int hend = strcspn(head, now);
    int start =  strcspn(now, head);
    strcpy(prev, now);
    int end, sum = 0;
    while(scanf("%s", now) != EOF){
        // printf("p: %s, n: %s\n", prev, now);
        end = strcspn(prev, now);
        // printf("start = %d, end = %d ", start, end);
        sum += (end-start);
        start =  strcspn(now, prev);
        // printf("%d\n",sum);
        strcpy(prev, now);
    }
    end = strcspn(prev, head);
    sum += (end-start);
    start =  strcspn(head, prev);
    sum += (hend-start);
    printf("%d",sum);
}