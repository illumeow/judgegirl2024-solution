#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int year, month, day;
} Date;

typedef struct {
    Date date;
    char catagory[36];
    int amount;
} Expense;

int cmp(const void *A, const void *B){
    const Expense *a = (const Expense *)A;
    const Expense *b = (const Expense *)B;
    if(a->date.year != b->date.year) return (a->date.year > b->date.year) - (a->date.year < b->date.year);
    if(a->date.month != b->date.month) return (a->date.month > b->date.month) - (a->date.month < b->date.month);
    if(a->date.day != b->date.day) return (a->date.day > b->date.day) - (a->date.day < b->date.day);
    return strcmp(a->catagory, b->catagory);
}

bool same(Expense *a, Expense *b){
    return (a->date.year == b->date.year &&
            a->date.month == b->date.month &&
            a->date.day == b->date.day &&
            strcmp(a->catagory, b->catagory) == 0);
}

void update(Expense *e, Expense arr[], int *n){
    for(int i = 0; i < *n; i++){
        if(same(e, arr+i)){
            arr[i].amount += e->amount;
            return;
        }
    }
    arr[(*n)++] = *e;
}

int main(){
    Expense expenses[10000], input;
    int n = 0;
    while(scanf("%d%d%d%s%d", &input.date.year, &input.date.month, &input.date.day, input.catagory, &input.amount) == 5)
        update(&input, expenses, &n);
    qsort(expenses, n, sizeof(Expense), cmp);
    for(int i = 0; i < n; i++)
        printf("%d %d %d %s %d\n", expenses[i].date.year, expenses[i].date.month, expenses[i].date.day, expenses[i].catagory, expenses[i].amount);
}