#include <stdio.h>

int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf)
            return EOF;
        p = buf;
    }
    return *p++;
}

int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}

int find(int book, long long bookshelf){
    for(int i = 0; i < 8; i++){
        int lastbook = bookshelf & 255;
        if((lastbook ^ book) == 0)
            return i;
        bookshelf >>= 8;
    }
    return -1;
}

int main(){
    int book;
    unsigned long long bookshelf = 0;
    while(ReadInt(&book)){
        int indx = find(book, bookshelf);
        if(indx == -1){
            bookshelf <<= 8;
            bookshelf |= book;
        }
        else{
            unsigned long long front;
            if(indx == 7) front = 0;
            else{
                front = bookshelf >> (indx+1)*8;
                front <<= (indx+1)*8;
            }
            unsigned long long back = bookshelf % (1LL << (indx*8));
            back <<= 8;
            bookshelf = (front | back | book);
        }
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