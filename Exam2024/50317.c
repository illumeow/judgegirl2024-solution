#include "map.h"
#include <string.h>
#include <stdlib.h>
 
int cmp(const void *A, const void *B){
    const struct element *a = (const struct element *)A;
    const struct element *b = (const struct element *)B;
    return strcmp(a->key, b->key);
}
 
void insert(Map *m, char key[], int value){
    struct element tar;
    strcpy(tar.key, key);
    struct element *found = bsearch(&tar, m->elements, m->end, sizeof(struct element), cmp);
    if(found == NULL){
        strcpy((m->elements)[m->end].key, key);
        (m->elements)[m->end].value = value;
        (m->end)++;
    }else{
        found->value = value;
    }
    qsort(m->elements, m->end, sizeof(struct element), cmp);
}
 
int delete(Map *m, char key[]){
    struct element tar;
    strcpy(tar.key, key);
    struct element *found = bsearch(&tar, m->elements, m->end, sizeof(struct element), cmp);
    if(found == NULL) return 0;
    (m->end)--;
    strcpy(found->key, (m->elements)[m->end].key);
    found->value = (m->elements)[m->end].value;
    qsort(m->elements, m->end, sizeof(struct element), cmp);
    return 1;
}
 
int query(Map *m, char key[]){
    struct element tar;
    strcpy(tar.key, key);
    struct element *found = bsearch(&tar, m->elements, m->end, sizeof(struct element), cmp);
    if(found == NULL) return -1;
    return found->value;
}