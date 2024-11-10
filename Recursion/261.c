#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void replace(char s[], char table[]){
    for(int i = 0; s[i] != '\0'; i++){
        if('A' <= s[i] && s[i] <= 'Z'){
            s[i] = table[s[i] - 'A'];
        }
    }
}

void solve(int idx, char letters[], int n, char table[], char a[], char b[], char c[]){
    if(idx == n){
        char tmpa[10], tmpb[10], tmpc[10];
        strcpy(tmpa, a); strcpy(tmpb, b); strcpy(tmpc, c);
        replace(tmpa, table); replace(tmpb, table); replace(tmpc, table);
        int numa = atoi(tmpa), numb = atoi(tmpb), numc = atoi(tmpc);
        if(numa*numb == numc){
            printf("%d x %d = %d\n", numa, numb, numc);
            exit(0);
        }
        return;
    }
    for(int i = 1; i <= 9; i++){
        table[letters[idx] - 'A'] = i + '0';
        solve(idx+1, letters, n, table, a, b, c);
    }
}

int main(){
    char a[10], b[10], c[10];
    scanf("%s%s%s", a, b, c);

    // arr[char-'0'] = digit
    char char2digit[30] = {};
    char letters[30] = {};
    int idx = 0;
    for(int i = 0; a[i] != '\0'; i++)
        if('A' <= a[i] && a[i] <= 'Z' && strchr(letters, a[i]) == NULL)
            letters[idx++] = a[i];
    for(int i = 0; b[i] != '\0'; i++)
        if('A' <= b[i] && b[i] <= 'Z' && strchr(letters, b[i]) == NULL)
            letters[idx++] = b[i];
    for(int i = 0; c[i] != '\0'; i++)
        if('A' <= c[i] && c[i] <= 'Z' && strchr(letters, c[i]) == NULL)
            letters[idx++] = c[i];
    letters[idx] = '\0';

    solve(0, letters, idx, char2digit, a, b, c);
}