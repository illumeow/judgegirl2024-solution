#include <stdio.h>
#include <string.h>

int main(){
    char *s = "abc//def/g";
    char *d = "/";
    char *p = strtok(s, d);
    while(p != NULL){
        printf("%s\n", p);
        p = strtok(NULL, d);
    }
}