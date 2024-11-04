#include <stdio.h>
#include <string.h>

int main(){
    char s[105];
    scanf("%s", s);
    
    int count[26] = {};
    for(int i = 0; i < strlen(s); i++){
        if('a' <= s[i] && s[i] <= 'z') count[s[i]-'a']++;
        else if('A' <= s[i] && s[i] <= 'Z') count[s[i]-'A']++;
    }
    for(int i = 0; i < 26; i++)
        printf("%d\n", count[i]);
}