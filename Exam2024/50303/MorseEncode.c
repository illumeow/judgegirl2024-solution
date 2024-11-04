#include <stdint.h>
#include <stdio.h>

#ifdef DEBUG
void printllu(uint64_t n) {
    printf("|");
    for (int i = 63; i >= 0; i--) {
        printf("%llu", (n >> i) & 1);
        if(i % 2 == 0) printf("|");
    }
}
#endif

void helper(int *shiftp, uint64_t* encoded_content, int *indxp){
    if(*shiftp < 31){
        encoded_content[*indxp] <<= 2;
        (*shiftp)++;
    }
    else{
        (*indxp)++;
        encoded_content[*indxp] = 0;
        *shiftp = 0;
    }
}

void MorseEncode(int* n, char str[], uint64_t* encoded_content){
    char* MorseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    int indx = 0, shift = 0;
    encoded_content[indx] = 0;
    for(int i = 0; str[i] != '\0'; i++){
        char* code = MorseCodes[str[i] - 'A'];
        for(int j = 0; code[j] != '\0'; j++){
            if(code[j] == '-'){
                encoded_content[indx] |= 1;
            }
            helper(&shift, encoded_content, &indx);
            #ifdef DEBUG
            printllu(encoded_content[indx]);
            printf("shift: %d\n", shift);
            #endif
        }
        if(str[i+1] != '\0'){
            encoded_content[indx] |= 2;
            helper(&shift, encoded_content, &indx);
            #ifdef DEBUG
            printllu(encoded_content[indx]);
            printf("white shift: %d\n", shift);
            #endif
        }
    }
    encoded_content[indx] |= 3;
    #ifdef DEBUG
    printllu(encoded_content[indx]);
    printf("while shift: %d\n", shift);
    #endif
    while(shift < 31){
        encoded_content[indx] <<= 2;
        encoded_content[indx] |= 3;
        shift++;
    }
    #ifdef DEBUG
    printllu(encoded_content[indx]);
    printf("shift: %d\n", shift);
    #endif
    *n = indx+1;
}