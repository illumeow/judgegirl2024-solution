#include "double_linked_tree.h"
#include <stdio.h>

void find_path(struct Node *root){
    if(root->left == NULL && root->right == NULL){
        root->next_clockwise = root->pre_clockwise = root;
        return;
    }
    if(root->left == NULL){
        find_path(root->right);
        root->next_clockwise = root->right->pre_clockwise;
        root->next_clockwise->pre_clockwise->next_clockwise = root;
        root->pre_clockwise = root->next_clockwise->pre_clockwise;
        root->next_clockwise->pre_clockwise = root;
        return;
    }
    if(root->right == NULL){
        find_path(root->left);
        root->next_clockwise = root->left->next_clockwise;
        root->next_clockwise->pre_clockwise = root;
        root->pre_clockwise = root->left;
        root->pre_clockwise->next_clockwise = root;
        return;
    }

    find_path(root->left);
    find_path(root->right);
    root->next_clockwise = root->right->pre_clockwise;
    root->next_clockwise->pre_clockwise->next_clockwise = root->left->next_clockwise;
    root->left->next_clockwise->pre_clockwise = root->next_clockwise->pre_clockwise;
    root->next_clockwise->pre_clockwise = root;
    root->pre_clockwise = root->left;
    root->left->next_clockwise = root;
}