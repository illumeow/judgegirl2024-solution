#include <stdio.h>

int main(){
    // int arr[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    // int *ptr = &(arr[0][0]);
    // for(int i = 0; i < 9; i++){
    //     printf("%d ", *(ptr+i));
    //     printf("%d\n", ptr[i]);
    // }
    // printf("\n");
    for(int i = 0; i < 12; i++){
        int a = (-i) % 3;
        int b = i % 3;
        printf("i=%d, %d %d\n", i, a, b);
    }
}