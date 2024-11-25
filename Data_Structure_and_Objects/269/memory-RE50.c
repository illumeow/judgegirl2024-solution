#include "memory-RE50.h"
#include <stdio.h>
#include <stdlib.h>
 
void initMemory(Memory *memory, int length){
    Memory *tmp = malloc(sizeof(Memory));
    tmp->start = 0;
    tmp->length = length;
    tmp->next = NULL;
    *memory = *tmp;
}
 
void printMemory(Memory *memory){
    printf("==========\n");
    while(memory){
        printf("start %d, length %d\n", memory->start, memory->length);
        memory = memory->next;
    }
}
 
void allocateMemory(Memory *memory, int start, int length){
    Memory *cur = memory, *prev = NULL;
    while(cur){
        if(cur->start <= start && start < cur->start + cur->length) break;
        prev = cur;
        cur = cur->next;
    }
    #ifdef DEBUG
    printf("===\nAlloc: found in [%d, %d] -- ", cur->start, cur->start + cur->length);
    #endif
    if(cur->start == start){
        /* front */
        #ifdef DEBUG
        printf("front\n");
        #endif
        cur->length -= length;
        if(cur->length == 0){
            #ifdef DEBUG
            printf("clear block\n");
            #endif
            if(cur->start == memory->start){
                #ifdef DEBUG
                printf("head | ");
                printf("next: [%d, %d]\n", cur->next->start, cur->next->start + cur->next->length);
                #endif
                *memory = *cur->next;
            }
            else prev->next = cur->next;
            free(cur);
            return;
        }
        cur->start = start + length;
    }else if(cur->start + cur->length == start + length){
        /* back */
        #ifdef DEBUG
        printf("back\n");
        #endif
        cur->length -= length;
    }else{
        /* mid */
        #ifdef DEBUG
        printf("mid\n");
        #endif
        Memory *tmp = malloc(sizeof(Memory));
        tmp->start = start + length;
        tmp->length = (cur->start + cur->length) - (start + length);
        tmp->next = cur->next;
        cur->length = start - cur->start;
        cur->next = tmp;
    }
}
 
void freeMemory(Memory *memory, int start, int length){
 
}