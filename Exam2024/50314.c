#include "tree.h"
#include <stdlib.h>

struct node *newnode(char data){
    struct node *node = malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void build_tree(char **code, char* str, struct node* root, int n){
    for(int i = 0; i < n; i++){
        struct node *current = root;
        for(int j = 0; code[i][j] != '\0'; j++){
            if(code[i][j] == '.'){
                if(current->left == NULL) current->left = newnode('?');
                current = current->left;
            }else{
                if(current->right == NULL) current->right = newnode('?');
                current = current->right;
            }
        }
        current->data = str[i];
    }
}

char ask(char* code, struct node* root){
    struct node *current = root;
    for(int i = 0; code[i] != '\0'; i++){
        if(code[i] == '.'){
            if(current->left == NULL) return 'E';
            current = current->left;
        }else{
            if(current->right == NULL) return 'E';
            current = current->right;
        }
    }
    return current->data;
}