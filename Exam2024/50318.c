#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
struct element{
    char key[25];
    int value;
};
 
struct map{
    int end;
    struct element elements[8005];
};
typedef struct map Map;
 
int cmp(const void *A, const void *B){
    const struct element *a = (const struct element *)A;
    const struct element *b = (const struct element *)B;
    return strcmp(a->key, b->key);
}

int query(Map *m, char key[]){
    struct element tar;
    strcpy(tar.key, key);
    struct element *found = bsearch(&tar, m->elements, m->end, sizeof(struct element), cmp);
    if(found == NULL) return 0;
    return found->value;
}

void create_or_incr(Map *m, char key[]){
    struct element tar;
    strcpy(tar.key, key);
    struct element *found = bsearch(&tar, m->elements, m->end, sizeof(struct element), cmp);
    if(found == NULL){
        strcpy(m->elements[m->end].key, key);
        m->elements[m->end].value = 1;
        m->end++;
        qsort(m->elements, m->end, sizeof(struct element), cmp);
    }else found->value++;
}

int main(){
    Map m;
    m.end = 0;
    char infile[24] = {}, outfile[24] = {};
    scanf("%s%s", infile, outfile);
    FILE *fin = fopen(infile, "r");
    int n; fscanf(fin, "%d", &n);
    for(int i = 0; i < n; i++){
        char key[30] = {};
        fscanf(fin, "%s", key);
        create_or_incr(&m, key);
    }
    rewind(fin);
    FILE *fout = fopen(outfile, "w");
    fscanf(fin, "%d", &n);
    for(int i = 1; i < n+1; i++){
        char s[30] = {};
        fscanf(fin, "%s", s);
        if(i % 7 != 0 && (query(&m, s) & 1))
            fprintf(fout, "%s\n", s);
    }
    fclose(fin);
    fclose(fout);
}