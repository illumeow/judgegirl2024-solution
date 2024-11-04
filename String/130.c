#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
    char tmp  = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int n;
    scanf("%d", &n);
    char *ans[] = {"no", "yes"};
    for(int _ = 0; _ < n; _++){
        char s1[85], s2[85];
        int similar = 0;
        scanf("%s%s", s1, s2);
        if(strcmp(s1, s2) == 0)
            similar = 1;
        else if(strlen(s1) == strlen(s2)){
            for(int i = 0; i < strlen(s1)-1; i++){
                swap(&s1[i], &s1[i+1]);
                if(strcmp(s1, s2) == 0){
                    similar = 1;
                    break;
                }
                swap(&s1[i], &s1[i+1]);
            }
        }
        else if(strlen(s1) - strlen(s2) == 1){
            for(int i = 0; i < strlen(s1); i++){
                char tmp[85];
                int indx = 0;
                for(int j = 0; j < strlen(s1); j++){
                    if(i == j) continue;
                    tmp[indx] = s1[j];
                    indx++;
                }
                tmp[indx] = '\0';
                if(strcmp(tmp, s2) == 0){
                    similar = 1;
                    break;
                }
            }
        }
        else if(strlen(s1) - strlen(s2) == -1){
            for(int i = 0; i < strlen(s2); i++){
                char tmp[85];
                int indx = 0;
                for(int j = 0; j < strlen(s2); j++){
                    if(i == j) continue;
                    tmp[indx] = s2[j];
                    indx++;
                }
                tmp[indx] = '\0';
                if(strcmp(tmp, s1) == 0){
                    similar = 1;
                    break;
                }
            }
        }
        printf("%s\n", ans[similar]);
    }
}