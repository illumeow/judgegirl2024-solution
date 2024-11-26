#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int data;
	struct node *next;
} Node;

Node *new_node(int data){
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void print_list(Node *head){
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(Node *head){
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void push_front(Node **head, int data){
    Node *tmp = new_node(data);
    tmp->next = *head;
    *head = tmp;
}

void push_back(Node **head, int data){
    Node **indirect = head;
    Node *tmp = new_node(data);
    while(*indirect) indirect = &((*indirect)->next);
    *indirect = tmp;
}

void remove_node(Node **head, int data) {
    Node **indirect = head;
    while(*indirect && (*indirect)->data != data)
        indirect = &((*indirect)->next);
    if(*indirect == NULL) return;
    Node *tmp = *indirect;
    *indirect = (*indirect)->next;
    free(tmp);
}

void reverse(Node **head){
    if(*head == NULL || (*head)->next == NULL) return;
    Node *prev = NULL, *cur = *head, *next = (*head)->next;
    while(next){
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;
    *head = cur;
}

int main(){
    char op[5];
    Node *head = NULL;
	while(scanf("%s", op) != EOF){
        if(strcmp(op, "p") == 0){
            print_list(head);
        }
        else if(strcmp(op, "pf") == 0){
            int data; scanf("%d", &data);
            push_front(&head, data);
        }else if(strcmp(op, "pb") == 0){
            int data; scanf("%d", &data);
            push_back(&head, data);
        }else if(strcmp(op, "r") == 0){
            int data; scanf("%d", &data);
            remove_node(&head, data);
        }else if(strcmp(op, "f") == 0){
            free_list(head);
            head = NULL;
        }else if(strcmp(op, "re") == 0){
            reverse(&head);
        }else if(strcmp(op, "q") == 0){
            break;
        }
    }
	return 0;
}