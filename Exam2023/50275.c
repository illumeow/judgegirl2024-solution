#include <stdio.h>
#include <string.h>

int main(){
    char *delim = " .,!?;:\n";
    char* suffix[20] = {"able", "ary", "ed", "ence", "ful", "hood", "ical", "ing", "ish", "ism", "ist", "ive", "ize", "less", "ly", "ment", "ness", "ous", "ship", "tion"};
    int suffix_cnt[20] = {};
    char read[100005];
    while(fgets(read, 100000, stdin) != NULL){
        char *p;
        p = strtok(read, delim);
        while(p != NULL){
            int toklen = strlen(p);
            for(int i = 0; i < 20; i++){
                int suflen = strlen(suffix[i]);
                if(strcmp(p+toklen-suflen, suffix[i]) == 0){
                    suffix_cnt[i]++;
                    break;
                }
            }
            p = strtok(NULL, delim);
        }
    }
    for(int i = 0; i < 20; i++)
        if(suffix_cnt[i])
            printf("%s:\nFrequency: %d\n", suffix[i], suffix_cnt[i]);
}