#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *A, const void *B){
    return strcmp((const char *)A, (const char *)B);
}

int main(){
    char buf[36];
    char strings[64][36];
    int n = 0;
    while(fgets(buf, 36, stdin) != NULL)
        strcpy(strings[n++], buf);
    qsort(strings, n, sizeof(char)*36, cmp);
    for(int i = 0; i < n; i++)
        printf("%s", strings[i]);
}