#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VARNAME_MAXLENGTH 8
#define VARNAME_MAXN 100
#define MAXLINE 1000

int read_variable(char varName[VARNAME_MAXN][VARNAME_MAXLENGTH], int varValue[VARNAME_MAXN]){
    char name[VARNAME_MAXLENGTH], eq[2];
    int value, cnt = 0;
    scanf("%s", name);
    while(strcmp(name, "END") != 0){
        scanf("%s%d", eq, &value);
        strcpy(varName[cnt], name);
        varValue[cnt] = value;
        cnt++;
        scanf("%s", name);
    }
    return cnt;
}

int main(){
    char varName[VARNAME_MAXN][VARNAME_MAXLENGTH];
    int varValue[VARNAME_MAXN];
    int varCount = read_variable(varName, varValue);
    #ifdef CHECKVAR
    for(int i = 0; i < varCount; i++) 
        printf("%s = %d\n", varName[i], varValue[i]);
    #endif
}