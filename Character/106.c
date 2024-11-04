#include <stdio.h>
#include <string.h>
#define abs(n) ((n >= 0)*n + (n < 0)*(-n))

int main(){
    char number[1005];
    char *ans[2] = {"no", "yes"};
    for(;;){
        scanf("%s", number);
        if(strcmp(number, "-1") == 0) return 0;
        // 2, 3, 5, 11
        int length = strlen(number);
        printf("%s ", ans[(((number[length-1] - 48) & 1) + 1) & 1]);

        int sum = 0;
        for(int i = 0; i < length; i++)
            sum += (number[i] - 48);

        printf("%s ", ans[(sum % 3) == 0]);
        printf("%s ", ans[((number[length-1] - 48) % 5) == 0]);

        int osum = 0, esum = 0;
        for(int i = 0; i < length; i++){
            if(i & 1) osum += (number[i] - 48);
            else esum += (number[i] - 48);
        }
        int diff = osum - esum;
        diff = abs(diff);
        printf("%s\n", ans[(diff % 11) == 0]);
    }
}