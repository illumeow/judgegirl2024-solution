#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Node *alloc_node(int start, int length){
    Node *node = malloc(sizeof(Node));
    node->start = start;
    node->length = length;
    node->next = NULL;
    return node;
}

void initMemory(Memory *memory, int length){
    memory->head = alloc_node(0, length);
}

void printMemory(Memory *memory){
    printf("==========\n");
    Node *cur = memory->head;
    while(cur){
        printf("start %d, length %d\n", cur->start, cur->length);
        cur = cur->next;
    }
}

void allocateMemory(Memory *memory, int start, int length){
    Node *cur = memory->head, *prev = NULL;
    while(!(cur->start <= start && start < cur->start + cur->length)){
        prev = cur;
        cur = cur->next;
    }
    #ifdef DEBUG
    printf("===\nAlloc: [%d, %d] found in [%d, %d] -- ", start, start + length, cur->start, cur->start + cur->length);
    #endif
    bool same_start = (cur->start == start), same_end = (cur->start + cur->length == start + length);
    if(same_start && same_end){
        /* completely overlay */
        #ifdef DEBUG
        printf("[A] completely overlay\n");
        #endif
        if(prev) prev->next = cur->next;
        else memory->head = cur->next;
    }
    else if(same_start){
        /* front */
        #ifdef DEBUG
        printf("[A] front\n");
        #endif
        cur->length -= length;
        cur->start = start + length;
    }else if(same_end){
        /* back */
        #ifdef DEBUG
        printf("[A] back\n");
        #endif
        cur->length -= length;
    }else{
        /* mid */
        #ifdef DEBUG
        printf("[A] mid\n");
        #endif
        Node *tmp = alloc_node(start + length, (cur->start + cur->length) - (start + length));
        tmp->next = cur->next;
        cur->length = start - cur->start;
        cur->next = tmp;
    }
}

void freeMemory(Memory *memory, int start, int length){
    Node *cur = memory->head, *prev = NULL;
    while(cur && !((prev == NULL || prev->start + prev->length <= start) && start < cur->start)){
        prev = cur;
        cur = cur->next;
    }
    #ifdef DEBUG
    if(prev && cur) printf("===\nFree: [%d, %d] found in [%d, %d] -- ", start, start + length, prev->start + prev->length, cur->start);
    #endif

    if(prev == NULL && cur == NULL){
        /* empty list */
        #ifdef DEBUG
        printf("[F] empty list\n");
        #endif
        Node *tmp = alloc_node(start, length);
        memory->head = tmp;
        return;
    }
    else if(prev == NULL){
        /* new head */
        #ifdef DEBUG
        printf("[F] new head\n");
        #endif
        if(cur->start == start + length){
            cur->start = start;
            cur->length += length;
        }else{
            Node *tmp = alloc_node(start, length);
            tmp->next = cur;
            memory->head = tmp;
        }
        return;
    }
    else if(cur == NULL){
        /* new tail */
        #ifdef DEBUG
        printf("[F] new tail\n");
        #endif
        if(prev->start + prev->length == start){
            prev->length += length;
        }else{
            Node *tmp = alloc_node(start, length);
            prev->next = tmp;
        }
        return;
    }

    bool same_start = prev->start + prev->length == start, same_end = cur->start == start + length;
    if(same_start && same_end){
        /* completely overlay */
        #ifdef DEBUG
        printf("[F] completely overlay\n");
        #endif
        prev->length += length + cur->length;
        prev->next = cur->next;
        free(cur);
    }
    else if(same_start){
        /* front */
        #ifdef DEBUG
        printf("[F] front\n");
        #endif
        prev->length += length;
    }else if(same_end){
        /* back */
        #ifdef DEBUG
        printf("[F] back\n");
        #endif
        cur->start = start;
        cur->length += length;
    }else{
        /* mid */
        #ifdef DEBUG
        printf("[F] mid\n");
        #endif
        Node *tmp = alloc_node(start, length);
        tmp->next = cur;
        prev->next = tmp;
    }
}