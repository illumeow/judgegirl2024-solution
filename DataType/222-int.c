#include <stdio.h>

int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            return EOF;    
        }
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

int main(){
    int bookshelf[8] = {};
    int book;
    while(ReadInt(&book)){
        int indx = 0;
        for(int i = 1; i < 8; i++){
            if(bookshelf[i] == book){
                indx = i;
                break;
            }
        }
        for(int i = indx; i < 7; i++)
            bookshelf[i] = bookshelf[i+1];
        bookshelf[7] = book;
    }
    for(int i = 0; i < 8; i++)
        printf("%d%c", bookshelf[i], " \n"[i == 7]);
}