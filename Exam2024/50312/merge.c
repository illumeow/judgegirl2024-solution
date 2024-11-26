#include <stdio.h>
#include <stdbool.h> 
#include "sort_list.h"
 
struct node *insert(struct node *cur, struct node *sorted){
    cur -> next_node = NULL;
    if (sorted == NULL) return cur;
    if (cur < sorted){
        cur -> next_node = sorted;
        return cur;
    }
    struct node *temp = sorted;
    while (temp -> next_node != NULL && temp -> next_node < cur) temp = temp -> next_node;
    cur -> next_node = temp -> next_node;
    temp -> next_node = cur;
    return sorted;
}
 
struct node *merge(struct node *left, struct node *pivot, struct node *right){
    if (left == NULL){
        pivot -> next_node = right;
        return pivot;
    }
    struct node *res = left;
    while (left -> next_node != NULL) left = left -> next_node;
    left -> next_node = pivot;
    left -> next_node -> next_node = right;
    return res;
}
 
struct node *sort_list(struct node *head){
    if (head == NULL) return head;
    if (head -> next_node == NULL) return head;
    if (head -> next_node -> next_node == NULL){
        if (head -> next_node > head) return head;
        struct node *temp = head -> next_node;
        temp -> next_node = head;
        temp -> next_node -> next_node = NULL;
        return temp;
    }
    struct node *left = NULL, *right = NULL, *pivot = head;
    struct node *temp = head -> next_node, *add, *left_tail, *right_tail;
    pivot -> next_node = NULL;
    while (temp != NULL){
        add = temp;
        temp = temp -> next_node;
        add -> next_node = NULL;
        if (add > pivot){
            if (right == NULL){
                right = add;
                right_tail = right;
            }
            else{
                right_tail -> next_node = add;
                right_tail = right_tail -> next_node;
            }
        }
        else{
            if (left == NULL){
                left = add;
                left_tail = left;
            }
            else{
                left_tail -> next_node = add;
                left_tail = left_tail -> next_node;
            }
        }
    }
    return merge(sort_list(left), pivot, sort_list(right));
}