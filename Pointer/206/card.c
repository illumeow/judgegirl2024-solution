#include <stdio.h>

void shuffle(int *deck[]){
    int *array[10000];
    int indx = 0;
    while(deck[indx] != NULL){
        array[indx] = deck[indx];
        indx++;
    }
    array[indx] = NULL;
    /* 
    indx cards, 0 ~ indx-1 
    first half n cards, 0 ~ n-1
    sec half indx-n cards, n ~ indx-1
    */
    int n = (indx+1)/2;
    indx = 0;
    for(int i = 0, j = n; i < n; i++, j++){
        deck[indx++] = array[i];
        deck[indx++] = array[j];
    }
}

void print(int *deck[]){
    int i = 0;
    if(deck[i] == NULL) return;
    printf("%d", *deck[i++]);
    while(deck[i] != NULL){
        printf(" %d", *deck[i]);
        i++;
    }
}