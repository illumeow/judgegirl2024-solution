#include <stdio.h>
#include <stdbool.h>
#define MAXN 100

// check if an interval [h, t] is palindrome
bool is_palindrome(int (*arr)[MAXN], int head, int tail){
    int length = tail - head + 1;
    #ifdef DEBUG
    printf("l: %d ", length);
    #endif
    if(length == 1) return 1;
    for(int i = 0; i < length / 2; i++){
        #ifdef DEBUG
        printf("i: %d ", i);
        printf("%d %d\n", (*arr)[head + i], (*arr)[tail - i]);
        #endif
        if((*arr)[head + i] != (*arr)[tail - i]) return 0;
    }
    return 1;
}

int main(){
    int num[MAXN];
    int n = 0;
    while(scanf("%d", &num[n]) != EOF){n++;}
    #ifdef INPUT
    for(int i = 0; i < n; i++){
        printf("%d ", num[i]);
    }
    printf("\n");
    #endif

    // [0, 1, 2, ..., n-1]
    // start from len(interval) = n
    for(int length = n; length > 1; length--){
        for(int tail = n-1; tail > length-2; tail--){
            int head = tail - length + 1;
            // printf("[%d, %d] ", head, tail);
            // [head, cut), [cut, tail]
            for(int cut = tail; cut > head; cut--){
                if(is_palindrome(&num, head, cut - 1) && is_palindrome(&num, cut, tail)){
                    for(int i = head; i < tail; i++) printf("%d ", num[i]);
                    printf("%d", num[tail]);
                    #ifdef DEBUG
                    printf("\n%d %d %d\n", head, cut, tail);
                    #endif
                    return 0;
                }
            }
        }
        // printf("\n");
    }
}