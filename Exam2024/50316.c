#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char c;
	struct node *prev, *next;
} Node;

typedef struct {
    Node *head, *tail;
    int size;
} Deque;

Node *new_node(char c){
    Node *node = malloc(sizeof(Node));
    node->c = c;
    node->prev = node->next = NULL;
    return node;
}

Deque *new_deque(){
    Deque *dq = malloc(sizeof(Deque));
    dq->head = dq->tail = NULL;
    dq->size = 0;
    return dq;
}

void push_front(Deque* dq, char c){
    Node *tmp = new_node(c);
    if(dq->size == 0){
        dq->head = dq->tail = tmp;
        dq->size = 1;
        return;
    }
    dq->head->prev = tmp;
    tmp->next = dq->head;
    dq->head = tmp;
    dq->size++;
}

void push_back(Deque *dq, char c){
    Node *tmp = new_node(c);
    if(dq->size == 0){
        dq->head = dq->tail = tmp;
        dq->size = 1;
        return;
    }
    dq->tail->next = tmp;
    tmp->prev = dq->tail;
    dq->tail = tmp;
    dq->size++;
}

char pop_front(Deque *dq){
    if(dq->size == 0) return 0;
    char c = dq->head->c;
    if(dq->size == 1)
        dq->head = dq->tail = NULL;
    else{
        Node *tmp = dq->head;
        dq->head = dq->head->next;
        dq->head->prev = NULL;
        free(tmp);
    }
    dq->size--;
    return c;
}

char pop_back(Deque *dq){
    if(dq->size == 0) return 0;
    char c = dq->tail->c;
    if(dq->size == 1)
        dq->head = dq->tail = NULL;
    else{
        Node *tmp = dq->tail;
        dq->tail = dq->tail->prev;
        dq->tail->next = NULL;
        free(tmp);
    }
    dq->size--;
    return c;
}

int remove_all(Deque *dq, char c){
    if(dq->size == 0) return 0;
    int cnt = 0;
    while(dq->size && dq->head->c == c){
        pop_front(dq);
        cnt++;
    }
    while(dq->size && dq->tail->c == c){
        pop_back(dq);
        cnt++;
    }
    Node *cur = dq->head;
    while(cur){
        if(cur->c == c){
            Node *tmp = cur;
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur = cur->next;
            free(tmp);
            cnt++;
            dq->size--;
        }else cur = cur->next;
    }
    return cnt;
}

int main(){
    Deque *dq = new_deque();
    int Q;
    scanf("%d", &Q);
    while(Q--){
        int op, cnt = 0;
        scanf("%d", &op);
        char c;
        switch(op){
            case 1:
                scanf(" %c", &c);
                push_front(dq, c);
                break;
            case 2:
                scanf(" %c", &c);
                push_back(dq, c);
                break;
            case 3:
                c = pop_front(dq);
                if(c) printf("1 %c\n", c);
                else printf("0\n");
                break;
            case 4:
                c = pop_back(dq);
                if(c) printf("1 %c\n", c);
                else printf("0\n");
                break;
            case 5:
                scanf(" %c", &c);
                cnt = remove_all(dq, c);
                if(cnt) printf("%d %c\n", cnt, c);
                else printf("0\n");
                break;
            case 6:
                printf("%d\n", dq->size);
                break;
            default: break;
        }
    }
}