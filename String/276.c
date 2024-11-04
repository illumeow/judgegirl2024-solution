#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main(){
    // ignore "of", "and", "the", and "at"
    char word[128];
    char abbr[128];
    bool end;
    int indx = 0;
    while(scanf("%s", word) != EOF){
        if(word[strlen(word)-1] == '.'){
            end = true;
            word[strlen(word)-1] = '\0';
        }
        if(strcmp(word, "of") != 0 && strcmp(word, "and") != 0 && 
           strcmp(word, "the") != 0 && strcmp(word, "at") != 0){
            abbr[indx] = toupper(word[0]);
            indx++;
        }
        if(end){
            abbr[indx] = '\0';
            printf("%s\n", abbr);
            indx = 0;
            end = false;
        }
    }
}