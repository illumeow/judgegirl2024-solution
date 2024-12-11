#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Pos;

int dis(const Pos *a, const Pos *b){
    return (a->x - b->x)*(a->x - b->x) + (a->y - b->y)*(a->y - b->y);
}

int cmp(const void *A, const void *B){
    const Pos *a = (const Pos *)A;
    const Pos *b = (const Pos *)B;
    const Pos origin = {0, 0};
    if(dis(a, &origin) != dis(b, &origin))
        return (dis(a, &origin) > dis(b, &origin))-(dis(a, &origin) < dis(b, &origin));
    if(a->x != b->x) return (a->x > b->x) - (a->x < b->x);
    return (a->y > b->y) - (a->y < b->y);
}

int main(){
    Pos cities[100000];
    int x, y, idx = 0;
    while(scanf("%d %d", &x, &y) == 2)
        cities[idx].x = x, cities[idx++].y = y;
    qsort(cities, idx, sizeof(Pos), cmp);
    int sum = cities[0].x*cities[0].x + cities[0].y*cities[0].y;
    for(int i = 1; i < idx; i++)
        sum += dis(&cities[i-1], &cities[i]);
    printf("%d", sum);
}