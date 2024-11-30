#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
        (*input)++;
        Node *node = new_node(-1);
        node->left = build_tree(input);
        (*input)++;
        node->right = build_tree(input);
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

void traverse_HRHL(Node *node);

void traverse_HLHR(Node *node){
    if(node == NULL) return;
    printf("%d\n", node->value);
    traverse_HRHL(node->left);
    printf("%d\n", node->value);
    traverse_HRHL(node->right);
}

void traverse_HRHL(Node *node){
    if(node == NULL) return;
    printf("%d\n", node->value);
    traverse_HLHR(node->right);
    printf("%d\n", node->value);
    traverse_HLHR(node->left);
}

int main(){
    char input[4005];
    scanf("%s", input);
    char *ptr = input;
    Node *root = build_tree(&ptr);
    fill_tree(root);
    traverse_HLHR(root);
    free_tree(root);
}