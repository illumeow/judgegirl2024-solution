#include <stdio.h>
#include <string.h>

void fuse(char *a, char *b){
    // l-1 0, l-2 1
    int best = 0;
    int max = (strlen(a) < strlen(b))? strlen(a): strlen(b);
    for(int i = 1; i <= max; i++){
        if(strncmp(&(a[strlen(a)-i]), b, i) == 0){
            best = i;
        }
    }
    strcat(a, b+best);
}

int main(){
    char ans[128];
    scanf("%s", ans);
    char tmp[128];
    while(scanf("%s", tmp) != EOF){
        fuse(ans, tmp);
        // printf("%s\nc", ans);
    }
    printf("%s", ans);
}