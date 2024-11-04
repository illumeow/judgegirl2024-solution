#include <stdint.h>
#include <string.h>
#include <stdio.h>

char code2char(char *code){
    char* MorseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    for(int i = 0; i < 26; i++)
        if(strcmp(MorseCodes[i], code) == 0)
            return (char)(i + 'A');
    return '?';
}

void MorseDecode(int n, const uint64_t encoded_content[] ,char ans[]){
    char code[25];
    int codeindx = 0, ansindx = 0;
    for(int i = 0; i < n; i++){
        uint64_t num = encoded_content[i];
        for(int j = 62; j >= 0; j -= 2){
            int codeNum = (num >> j) & 3;
            // printf("%d ", codeNum);
            switch(codeNum){
                case 0:
                    code[codeindx++] = '.';
                    break;
                case 1:
                    code[codeindx++] = '-';
                    break; 
                case 2:
                    code[codeindx] = '\0';
                    ans[ansindx++] = code2char(code);
                    codeindx = 0;
                    break;
                case 3:
                    code[codeindx] = '\0';
                    ans[ansindx++] = code2char(code);
                    ans[ansindx] = '\0';
                    return;
                    break;
            }
        }
    }
}