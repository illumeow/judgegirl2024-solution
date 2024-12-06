#include "heap.h"
#include <string.h>

/* all elements are positive */
/* capacity = MAXHEAP */

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(struct Heap *heap, int i){
    int min = i, left = 2*i+1, right = 2*i+2;
    if(left < heap->num && heap->ary[left] < heap->ary[min]) min = left;
    if(right < heap->num && heap->ary[right] < heap->ary[min]) min = right;
    if(min != i){
        swap(&(heap->ary[min]), &(heap->ary[i]));
        heapify(heap, min);
    }
}

void initialize(struct Heap *heap){
    memset(heap->ary, 0, MAXHEAP);
    heap->num = 0;
}

int removeMin(struct Heap *heap){
    int root = heap->ary[0];
    heap->ary[0] = heap->ary[--heap->num];
    heapify(heap, 0);
    return root;
}

void add(struct Heap *heap, int i){
    int cur = heap->num;
    heap->ary[heap->num++] = i;
    while(cur != 0 && heap->ary[cur] < heap->ary[(cur - 1) / 2]){
        swap(&(heap->ary[cur]), &(heap->ary[(cur - 1) / 2]));
        cur = (cur - 1) / 2;
    }
}

int isFull(struct Heap *heap){
    return (heap->num == MAXHEAP);
}

int isEmpty(struct Heap *heap){
    return (heap->num == 0);
}