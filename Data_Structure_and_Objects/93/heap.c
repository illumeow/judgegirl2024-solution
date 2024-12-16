#include "heap.h"
#include <string.h>

/* all elements are positive */
/* capacity = MAXHEAP */

#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(struct Heap *heap, int i){
    int min = i;
    if(lc(i) < heap->num && heap->ary[lc(i)] < heap->ary[min]) min = lc(i);
    if(rc(i) < heap->num && heap->ary[rc(i)] < heap->ary[min]) min = rc(i);
    if(min != i){
        swap(&(heap->ary[min]), &(heap->ary[i]));
        heapify(heap, min);
    }
}

void initialize(struct Heap *heap){
    memset(heap->ary, 0, MAXHEAP);
    heap->num = 1;
}

int removeMin(struct Heap *heap){
    int root = heap->ary[1];
    heap->ary[1] = heap->ary[--heap->num];
    heapify(heap, 1);
    return root;
}

void add(struct Heap *heap, int i){
    int cur = heap->num;
    heap->ary[heap->num++] = i;
    while(cur != 1 && heap->ary[cur] < heap->ary[cur / 2]){
        swap(&(heap->ary[cur]), &(heap->ary[cur / 2]));
        cur >>= 1;
    }
}

int isFull(struct Heap *heap){
    return (heap->num == MAXHEAP);
}

int isEmpty(struct Heap *heap){
    return (heap->num == 1);
}