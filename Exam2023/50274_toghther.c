#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *A, const void *B){
    const char *a = (const char *)A;
    const char *b = (const char *)B;
    return strcmp(a, b);
}

int main(){
    char *delim = ".,!?;:[](){} \n";
    char s1[100005], s2[100005];
    fgets(s1, 100005, stdin);
    fgets(s2, 100005, stdin);

    char token[2005][105];
    int tcnt = 0;
    char *p;
    p = strtok(s1, delim);
    while(p != NULL){
        strcpy(token[tcnt], p);
        tcnt++;
        p = strtok(NULL, delim);		   
    }
    p = strtok(s2, delim);
    while (p != NULL) {
        strcpy(token[tcnt], p);
        tcnt++;
        p = strtok(NULL, delim);		   
    }

    for(int i = 0; i < tcnt; i++)
        printf("%s|", token[i]);
    printf("\n");

    qsort(token, tcnt, sizeof(char)*105, cmp);
    char ans[200005] = "";
    for(int i = 0; i < tcnt; i++)
        strcat(ans, token[i]);
    printf("%s", ans);
}