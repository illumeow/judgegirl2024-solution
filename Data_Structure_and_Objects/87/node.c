#include "node.h"
#include <stdio.h>

struct node *merge(struct node *list1, struct node *list2){
    struct node *cur1 = list1, *cur2 = list2, *head, *cur;
    if(cur1->value < cur2->value){
        head = cur = cur1;
        cur1 = cur1->next;
    }else{
        head = cur = cur2;
        cur2 = cur2->next;
    }
    while(cur1 != NULL && cur2 != NULL){
        if(cur1->value < cur2->value){
            cur->next = cur1;
            cur1 = cur1->next;
        }else{
            cur->next = cur2;
            cur2 = cur2->next;
        }
        cur = cur->next;
        // printf("%d: ", cur->value);
        // if(cur1 != NULL) printf("cur1: %d ", cur1->value);
        // if(cur2 != NULL) printf("cur2: %d ", cur2->value);
        // if(cur1 != NULL || cur2 != NULL) printf("\n");
        // print(head);
        // printf("\n");
    }
    if(cur1 == NULL) cur->next = cur2;
    if(cur2 == NULL) cur->next = cur1;
    return head;
}