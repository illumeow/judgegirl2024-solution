#include <stdio.h>

void printll(long long n) {
    printf("|");
    for (int i = 63; i >= 0; i--) {
        printf("%lld", (n >> i) & 1);
        if(i % 8 == 0) printf("|");
    }
    printf("\n");
}

void printByte(int n) {
    printf("|");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("|\n");
}

int find(int book, long long bookshelf){
    #ifdef FIND
    printf("finding %d: ", book);
    printByte(book);
    #endif
    for(int i = 0; i < 8; i++){
        int lastbook = bookshelf & 255;
        #ifdef FIND
        printf("%d: ", i);
        printByte(lastbook);
        #endif
        if((lastbook ^ book) == 0)
            return i;
        bookshelf >>= 8;
    }
    return -1;
}

int main(){
    int book;
    unsigned long long bookshelf = 0;
    while(scanf("%d", &book) != EOF){
        int indx = find(book, bookshelf);
        #ifdef DEBUG
        printf("%d = ", book);
        printByte(book);
        #endif
        if(indx == -1){
            #ifdef DEBUG
            printf("plug in\n");
            #endif
            bookshelf <<= 8;
            bookshelf |= book;
        }
        else{
            #ifdef DEBUG
            printf("merge\n");
            #endif
            #ifdef MERGE
            printf("found %d at [%d]\n", book, indx);
            #endif
            unsigned long long front;
            if(indx == 7) front = 0;
            else{
                front = bookshelf >> (indx+1)*8;
                front <<= (indx+1)*8;
            }
            unsigned long long back = bookshelf % (1LL << (indx*8));
            #ifdef MERGE
            printll(front);
            printll(back);
            printf("========\n");
            #endif
            back <<= 8;
            bookshelf = (front | back | book);
        }
        #ifdef DEBUG
        printll(bookshelf);
        #endif
    }    
    // output your answer
    for(int i = 7; i >= 0; i--){
        unsigned long long nowbook = bookshelf & 0xFF00000000000000;
        nowbook >>= 56;
        printf("%llu ", nowbook);
        bookshelf <<= 8;
    }
    return 0;
}