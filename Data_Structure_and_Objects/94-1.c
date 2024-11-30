#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node *left;
    struct node *right;
    struct node *parent;
} Node;

Node *new_node(int value){
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void print_tree(Node *node) {
    if (node == NULL) return;

    // Print the value of the current node (Root)
    printf("%d -> ", node->value);

    // Traverse the left subtree (Left)
    print_tree(node->left);

    // Traverse the right subtree (Right)
    printf("\nv\n");
    print_tree(node->right);
}

void build_tree(char input[], Node *node, Node* root){
    for(int i = 0; input[i]; i++){
        if(input[i] == '('){
            node->left = new_node(-1);
            node->left->parent = node;
            node = node->left;
        }else if(input[i] == ','){
            node->right = new_node(-1);
            node->right->parent = node;
            node = node->right;
        }else if(input[i] == ')'){
            node = node->parent;
        }else{
            int value = 0;
            while(isdigit(input[i])){
                value = value * 10 + (input[i] - '0');
                i++;
            }
            i--;
            node->value = value;
            node = node->parent;
        }
    }
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
        printf("%d\n", node->value);
        traverse(node->right, true);
        printf("%d\n", node->value);
        traverse(node->left, true);
    }
}

int main(){
    char input[4005];
    scanf("%s", input);
    Node *root = new_node(-1);
    build_tree(input, root, root);
    fill_tree(root);
    traverse(root, true);
    free_tree(root);
}