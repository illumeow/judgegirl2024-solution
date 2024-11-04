#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool valid_name(const char *s){
    return (strcmp(s, "if") != 0 && strcmp(s, "else") != 0 && strcmp(s, "while") != 0 && 
       strcmp(s, "for") != 0 && strcmp(s, "switch") != 0 && strcmp(s, "case") != 0 && 
       strcmp(s, "break") != 0 && strcmp(s, "return") != 0 && strcmp(s, "void") != 0 && 
       strcmp(s, "int") != 0 && strcmp(s, "float") != 0 && strcmp(s, "char") != 0 &&
       s[0] != '\0' && !isdigit(s[0]));
}

int main(){
    /* the frequency of different variable and function names,
    Variable and function names do not include reserved words. 
    The name consists of digits, alphabets, and underscores '_'.
    The name starts with an alphabet or an underscore '_'. */
    char name[30][35] = {{}};
    int frequency[30] = {};
    char c;
    char s[35];
    int indx = 0, cnt = 0;
    while(scanf("%c", &c) != EOF){
        if(isalnum(c) || c == '_'){
            s[indx] = c;
            indx++;
        }
        else{
            s[indx] = s[24] = '\0';
            if(valid_name(s)){
                // printf("process: '%s'\n", s);
                int wordindx = -1;
                for(int i = 0; i < cnt; i++)
                    if(strcmp(s, name[i]) == 0)
                        wordindx = i;
                if(wordindx == -1){
                    strcpy(name[cnt], s);
                    frequency[cnt] = 1;
                    cnt++;
                }
                else frequency[wordindx]++;
                
            }
            indx = 0;
        }
    }
    for(int i = 0; i < cnt; i++)
        printf("%s %d\n", name[i], frequency[i]);
}