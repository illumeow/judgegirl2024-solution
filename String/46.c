#include <stdio.h>
#include <string.h>
#define MAXN 50005
 
int main(){
    char word[MAXN] = {}, cmd[10], pos[10], x;
    int tail = -1;
    while(scanf("%s", cmd) != EOF){
        if(strcmp(cmd, "insert") == 0){
            scanf("%s %c", pos, &x);
            if(strcmp(pos, "left") == 0){
                memmove(word+1, word, strlen(word)+1);
                word[0] = x;
                tail++;
            }
            else if(strcmp(pos, "right") == 0){
                word[tail+1] = x;
                word[tail+2] = '\0';
                tail++;
            }
            else{
                int k;
                sscanf(pos, "%d", &k);
                memmove(word+k, word+k-1, strlen(word+k-1)+1);
                word[k-1] = x;
                tail++;
            }
        }
        else if(strcmp(cmd, "delete") == 0){
            scanf("%s", pos);
            if(strcmp(pos, "left") == 0){
                memmove(word, word+1, strlen(word));
                tail--;
            }
            else if(strcmp(pos, "right") == 0){
                word[tail] = '\0';
                tail--;
            }
            else{
                int k;
                sscanf(pos, "%d", &k);
                memmove(word+k-1, word+k, strlen(word+k-1));
                tail--;
            }
        }
        #ifdef DEBUG
        printf("tail: %d | %s\n", tail, word);
        #endif
    }

    int maxl = 0, nowl = 0;
    char prev = '\0';
    char ans[MAXN];
    int indx = 0;
    for(int i = 0; i < strlen(word); i++){
        // update nowl
        if(prev == word[i]) nowl++;
        else{
            nowl = 1;
            prev = word[i];
        }
        // determine if append to ans
        if(nowl > maxl){
            maxl = nowl;
            ans[0] = word[i];
            indx = 1;
        }
        else if(nowl == maxl){
            ans[indx++] = word[i];
        }
    }

    for(int i = 0; i < indx; i++)
        printf("%c ", ans[i]);
    printf("%d", maxl);
}