#include <stdio.h>
#include <string.h>

int cmp(const void *A, const void *B){
    const char *a = (const char *)A;
    const char *b = (const char *)B;
    return strcmp(a, b);
}

int main(){
    char suffix[20][5] = {"ed", "ing", "ish", "ist", "ary", "tion", "ly", "ive", "ize", "ical",
                    "ness", "able", "less", "ment", "ence", "ful", "ous", "ism", "ship", "hood"};
    for(int i = 0; i < 20; i++)
        printf("%s ", suffix[i]);
    printf("\n");
    qsort(suffix, 20, sizeof(char)*5, cmp);
    for(int i = 0; i < 20; i++)
        printf("\"%s\", ", suffix[i]);
    printf("\n");
}