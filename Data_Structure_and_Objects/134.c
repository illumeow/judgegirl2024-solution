#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000

typedef struct treenode{
    int key;
    struct treenode *left, *right;
} TreeNode;

typedef struct node{
    int key, level;
} Node;

TreeNode *newTreeNode(int key){
    TreeNode *node = malloc(sizeof(TreeNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

int cmp_level(const void *A, const void *B){
    const Node *a = A, *b = B;
    return (a->level > b->level)-(a->level < b->level);
}

TreeNode *insertNode(TreeNode *root, int key){
    if(root == NULL) return newTreeNode(key);
    if(key < root->key) root->left = insertNode(root->left, key);
    else root->right = insertNode(root->right, key);
    return root;
}

int depth(TreeNode *root, int key, int cur_d){
    if(key == root->key) return cur_d;
    if(key < root->key) return depth(root->left, key, cur_d+1);
    else return depth(root->right, key, cur_d+1);
}

int solve(TreeNode *root, int a, int b){
    if(a < root->key && b < root->key) return solve(root->left, a, b);
    else if(a > root->key && b > root->key) return solve(root->right, a, b);
    else return depth(root, a, 0) + depth(root, b, 0);
}

int main(){
    int n;
    scanf("%d", &n);
    Node nodes[MAXN+5] = {};
    for(int i = 0; i < n; i++)
        scanf("%d %d", &nodes[i].key, &nodes[i].level);
    qsort(nodes, n, sizeof(Node), cmp_level);

    TreeNode *root = newTreeNode(nodes[0].key);
    for(int i = 1; i < n; i++)
        insertNode(root, nodes[i].key);
    
    int p;
    scanf("%d", &p);
    for(int i = 0; i < p; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", solve(root, a, b));
    }
}