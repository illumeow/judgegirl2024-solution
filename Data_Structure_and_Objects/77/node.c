#include "node.h"
#include <stdio.h>

struct node *getNode(struct node *head, unsigned int i){
    unsigned int size = 0;  // [0, size]
    struct node *cur = head;
    while(cur->next != NULL){
        size++;
        cur = cur->next;
    }
    if(i > size) return NULL;
    struct node *ret = head;
    for(int indx = 0; indx < size-i; indx++)
        ret = ret->next;
    return ret;
}