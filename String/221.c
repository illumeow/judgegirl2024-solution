#include <stdio.h>
#include <string.h>

int main(){
    int m;
    scanf("%d", &m);
    char s[260], content[260][260];
    int len = 0, indx = 0;
    while(scanf("%s", s) != EOF){
        if(len + strlen(s) > m){
            int space = m-len+1;
            if(indx == 1){
                printf("%s", content[0]);
                for(int j = 0; j < space; j++) printf(" ");
                printf("\n");
            }else{
                int base_space = space / (indx-1);
                int extra_space = space % (indx-1);
                for(int i = 0; i < indx-1; i++){
                    printf("%s ", content[i]);
                    for(int j = 0; j < base_space; j++) printf(" ");
                    if(extra_space){
                        printf(" ");
                        extra_space--;
                    }
                }
                printf("%s\n", content[indx-1]);
            }
            fflush(stdout);
            indx = 0;
            len = strlen(s);
            len++;
            strcpy(content[indx], s);
            indx++;
        }
        else{
            len += strlen(s);
            len++;
            strcpy(content[indx], s);
            indx++;
        }
    }
    int space = m-len+1;
    if(indx == 1){
        printf("%s", content[0]);
        for(int j = 0; j < space; j++) printf(" ");
        printf("\n");
    }else{
        int base_space = space / (indx-1);
        int extra_space = space % (indx-1);
        for(int i = 0; i < indx-1; i++){
            printf("%s ", content[i]);
            for(int j = 0; j < base_space; j++) printf(" ");
            if(extra_space){
                printf(" ");
                extra_space--;
            }
        }
        printf("%s\n", content[indx-1]);
    }
    fflush(stdout);
}