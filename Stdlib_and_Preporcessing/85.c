#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year, month, day;
} Date;

int cmp(const void *A, const void *B){
    const Date *a = (const Date *)A;
    const Date *b = (const Date *)B;
    if(a->year != b->year) return (a->year > b->year) - (a->year < b->year);
    if(a->month != b->month) return (a->month > b->month) - (a->month < b->month);
    return (a->day > b->day) - (a->day < b->day);
}

int main(){
    int n;
    scanf("%d", &n);
    Date* dates = malloc(sizeof(Date)*n);
    for(int i = 0; i < n; i++)
        scanf("%d %d %d", &dates[i].year, &dates[i].month, &dates[i].day);
    qsort(dates, n, sizeof(Date), cmp);
    for(int i = 0; i < n; i++)
        printf("%d %d %d\n", dates[i].year, dates[i].month, dates[i].day);
    free(dates);
}