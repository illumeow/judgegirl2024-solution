#include <stdint.h>
#include <stdio.h>

void printllu(uint64_t n) {
    printf("|");
    for (int i = 63; i >= 0; i--) {
        printf("%llu", (n >> i) & 1);
        if(i % 2 == 0) printf("|");
    }
}

void MorseEncode(int* n, char str[], uint64_t* encoded_content){
    char* MorseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    int count = 0;
    int location = 0;
    int strcount = 0;
    int idx = 0;
    encoded_content[idx] = 0;
    while (str[count] != '\0'){
        char *code = MorseCodes[str[count] - 'A'];
        location = 0;
        while(code[location] != '\0'){
            encoded_content[idx] <<= 2;
            if (code[location] == '-'){
                encoded_content[idx] |= 1;
            }
            strcount += 2;
            if (strcount == 64){
                idx++;
                encoded_content[idx] = 0;
                strcount = 0;
            }
            location++;
            // printllu(encoded_content[idx]);
            // printf("strcount: %d\n", strcount);
        }
        if(str[count+1] != '\0'){
            encoded_content[idx] <<= 2;
            encoded_content[idx] |= 2;
        }
        // printllu(encoded_content[idx]);
        // printf("strcount: %d\n", strcount);
        strcount += 2;
        if (strcount == 64){
            idx++;
            encoded_content[idx] = 0;
            strcount = 0;
        }
        count++;
    }

    for (int i = strcount; i <= 64; i += 2){
        encoded_content[idx] <<= 2;
        encoded_content[idx] |= 3;
    }
    // printllu(encoded_content[idx]);
    // printf("strcount: %d\n", strcount);
    *n = idx+1;
}