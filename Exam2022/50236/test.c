#include <stdio.h>
#include <string.h>

int main(){
    char *L = "abcde";
    char *p = strchr(L, 'a');
    printf("%p\n", L);
    printf("%p\n%ld|%c\n", p, p-L, *p);
}