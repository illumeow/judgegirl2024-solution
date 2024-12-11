#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string_count {
    char seen[80];
    int count;
};

int compare_and_add(char *string, struct string_count strings[]){
    int i;
    for(i = 0; strings[i].count > 0; i++){
        if(strcmp(string, strings[i].seen) == 0){
            strings[i].count++;
            return 1;
        }
    }
    strcpy(strings[i].seen, string);
    strings[i].count++;
    return 0;
}

int cmp(const void *A, const void *B){
    struct string_count *a = (struct string_count *)A, *b = (struct string_count *)B;
    if(a->count == b->count) return strcmp(a->seen, b->seen);
    return (a->count > b->count) - (a->count < b->count);
}

void sort(struct string_count strings[]){
    int n;
    for(n = 0; strings[n].count > 0; n++){}
    qsort(strings, n, sizeof(struct string_count), cmp);
}

void print(struct string_count strings[]){
    for(int i = 0; strings[i].count > 0; i++)
        printf("%d %s\n", strings[i].count, strings[i].seen);
}
