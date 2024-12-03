#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *next;
} Node;

Node *newnode(int num){
    Node *node = malloc(sizeof(Node));
    node->num = num;
    node->next = NULL;
    return node;
}

void push(Node **head, int num){
    Node *node = newnode(num);
    node->next = *head;
    *head = node;
}

int pop(Node **head){
    if(*head == NULL) return -1;
    Node *node = *head;
    *head = node->next;
    int num = node->num;
    free(node);
    return num;
}

int find(const char s[], const char arr[][40], const int n){
    for(int i = 0; i < n; i++)
        if(strcmp(s, arr[i]) == 0)
            return i;
    return -1;
}

int tokenize(char input[], char tokens[][40]){
    char *p, *delim = " ()\n";
    p = strtok(input, delim);
    int i = 0;
    while(p != NULL){
        strcpy(tokens[i], p);
        p = strtok(NULL, delim);
        i++;
    }
    return i;
}

int main(){
    char input[1005];
    fgets(input, 1005, stdin);
    char varname[50][40] = {{}};
    int varvalue[50] = {}, n = 0;
    while(scanf("%s = %d", varname[n], &varvalue[n]) == 2) n++;
    char tokens[1000][40] = {{}};
    int tokcnt = tokenize(input, tokens);

    int idx, a, b;
    Node *head = NULL;
    for(int i = tokcnt - 1; i >= 0; i--){
        /* operator */
        if(strcmp(tokens[i], "+") == 0){
            a = pop(&head), b = pop(&head);
            push(&head, a + b);
        }
        else if(strcmp(tokens[i], "-") == 0){
            a = pop(&head), b = pop(&head);
            push(&head, a - b);
        }
        else if(strcmp(tokens[i], "*") == 0){
            a = pop(&head), b = pop(&head);
            push(&head, a * b);
        }
        else if(strcmp(tokens[i], "/") == 0){
            a = pop(&head), b = pop(&head);
            push(&head, a / b);
        }
        /* var */
        else if((idx = find(tokens[i], varname, n)) != -1) push(&head, varvalue[idx]);
        /* num */
        else push(&head, atoi(tokens[i]));
    }
    printf("%d\n", pop(&head));
}