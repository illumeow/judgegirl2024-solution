#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool add(int *n){
    (*n)++;
    return true;
}

int main(){
    // number of digits, letters, vowels, and consonants
    char s[105];
    int digit = 0, letter = 0, vowel = 0;
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        char c = s[i];
        (isdigit(c) && add(&digit));
        (isalpha(c) && add(&letter));
        vowel += (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                  c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    printf("%d %d %d %d\n", digit, letter, vowel, letter-vowel);
}