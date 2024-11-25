#include "sort_list.h"
#include <stdio.h>

struct node *sort_list(struct node *head){
    struct node *cur = head;
    int size = 0;
    while(cur != NULL){
        cur = cur->next_node;
        size++;
    }
    struct node *prev = NULL, *nowhead = head;
    for(int i = size-1; i > 0; i--){
        cur = nowhead;
        for(int j = 0; j < i; j++){
            if(cur > cur->next_node){
                struct node *tmp = cur->next_node;
                if(cur == nowhead){
                    cur->next_node = cur->next_node->next_node;
                    nowhead = tmp;
                }else{
                    prev->next_node = tmp;
                    cur->next_node = tmp->next_node;
                }
                tmp->next_node = cur;
                prev = tmp;
            }else{
                prev = cur;
                cur = cur->next_node;
            }
        }
    }
    return nowhead;
}