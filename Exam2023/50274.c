#include <stdio.h>
#include <string.h>

int main(){
    char *delim = ".,!?;:[](){} \n";
    char s1[100005], s2[100005];
    fgets(s1, 100005, stdin);
    fgets(s2, 100005, stdin);

    char token1[1005][105], token2[1005][105];
    int tcnt1 = 0;
    char *p;
    p = strtok(s1, delim);
    while(p != NULL){
        strcpy(token1[tcnt1], p);
        tcnt1++;
        p = strtok(NULL, delim);		   
    }
    int tcnt2 = 0;
    p = strtok(s2, delim);
    while (p != NULL) {
        strcpy(token2[tcnt2], p);
        tcnt2++;
        p = strtok(NULL, delim);		   
    }

    // for(int i = 0; i < tcnt1; i++)
    //     printf("%s|", token1[i]);
    // printf("\n");
    // for(int i = 0; i < tcnt2; i++)
    //     printf("%s|", token2[i]);
    // printf("\n");

    int indx1 = 0, indx2 = 0;
    while(indx1 < tcnt1 && indx2 < tcnt2){
        if(strcmp(token1[indx1], token2[indx2]) < 0){
            printf("%s", token1[indx1]);
            indx1++;
        }else{
            printf("%s", token2[indx2]);
            indx2++;
        }
    }
    if(indx1 < tcnt1)
        while(indx1 < tcnt1)
            printf("%s", token1[indx1++]);
    else
        while(indx2 < tcnt2)
            printf("%s", token2[indx2++]);
}