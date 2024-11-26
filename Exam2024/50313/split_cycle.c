#include "split_cycle.h"
 
int split_cycle(struct Node *head, int A, int K){
    struct Node *cur = head->nxt, *tail = head;
    int size = 1;
    while(cur != head){
        size++;
        tail = cur;
        cur = cur->nxt;
    }
    if(size <= K){
        cur = head->nxt;
        int sum = head->val;
        while(cur != head){
            sum += cur->val;
            cur = cur->nxt;
        }
        return sum * A;
    }
    int new_idx = (size + 1) / 2;
    cur = head;
    for(int i = 1; i < new_idx; i++) cur = cur->nxt;
    tail->nxt = cur->nxt;
    cur->nxt = head;
    return split_cycle(head, A+1, K) + split_cycle(tail, A+2, K);
}