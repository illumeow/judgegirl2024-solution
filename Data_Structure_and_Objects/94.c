#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node *left;
    struct node *right;
} Node;

Node *new_node(int value){
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *build_tree(char **input){
    /* (*input): ptr to char processing now */
    if(**input == '\0') return NULL;

    if(**input == '('){
        /* next is value */
        (*input)++;
        Node *node = new_node(-1);
        node->left = build_tree(input);
        /* next is ',' */
        (*input)++;
        node->right = build_tree(input);
        /* next is ')' */
        (*input)++;
        return node;   
    } else if(isdigit(**input)){
        int value = 0;
        while(isdigit(**input)){
            value = value * 10 + (**input - '0');
            (*input)++;
        }
        return new_node(value);
    }
    
    return NULL;
}

void fill_tree(Node *node){
    if(node->left == NULL && node->right == NULL) return;
    fill_tree(node->left);
    fill_tree(node->right);
    node->value = node->left->value + node->right->value;
}

void free_tree(Node *node){
    if(node == NULL) return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

void traverse(Node *node, bool is_HLHR){
    if(node == NULL) return;
    if(is_HLHR){
        printf("%d\n", node->value);
        traverse(node->left, false);
        printf("%d\n", node->value);
        traverse(node->right, false);
    }else{
        traverse(node->right, true);
        printf("%d\n", node->value);
        traverse(node->left, true);
        printf("%d\n", node->value);
    }
}

int main(){
    char input[4005];
    scanf("%s", input);
    char *ptr = input;
    Node *root = build_tree(&ptr);
    fill_tree(root);
    traverse(root, true);
    free_tree(root);
}