#include <stdio.h>
#include "node.h"

void my_print(struct node *root, int path[], int idx){
    path[idx++] = root->data;
    if(root->left == NULL && root->right == NULL){
        for(int i = 0; i < idx; i++)
            printf("%d%c", path[i], " \n"[i==idx-1]);
        return;
    }
    if(root->left) my_print(root->left, path, idx);
    if(root->right) my_print(root->right, path, idx);
}

void print_all_paths(struct node *root){
    int path[1005] = {};
    my_print(root, path, 0);
}