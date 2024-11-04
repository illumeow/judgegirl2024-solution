#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char c, s[105];
    while(scanf("%c", &c) != EOF){
        if(isspace(c)){
            while(1){
                scanf("%c", &c);
                if(!isspace(c))
                    break;
            }
        }
        int indx = 0;
        s[indx] = c;
        indx++;
        while(1){
            scanf("%c", &c);
            if(c == '\n')
                break;
            s[indx] = c;
            indx++;
        }
        for(int i = strlen(s)-1; i >= 0; i--){
            // printf("[%c] ", s[i]);
            if(s[i] != ' '){
                s[i+1] = '\0';
                // printf("%d: [%c]\n", i, s[i]);
                break;
            }
        }
        printf("%s\n", s);
    }
}