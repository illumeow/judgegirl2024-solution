#include <stdio.h>
#include <string.h>

void hprint(int n, int w){
    printf(" ");
    for(int i = 0; i < w-3; i++)
        printf("%d", n);
    printf("  ");
}

void vuprint(int n, int w){
    if(n != 1 && n != 2 && n != 3)
        printf("%d", n);
    else printf(" ");
    for(int i = 0; i < w-3; i++)
        printf(" ");
    if(n != 5 && n != 6)
        printf("%d ", n);
    else printf("  ");
}

void vdprint(int n, int w){
    if(n == 0 || n == 2 || n == 6 || n == 8)
        printf("%d", n);
    else printf(" ");
    for(int i = 0; i < w-3; i++)
        printf(" ");
    if(n != 2 )
        printf("%d ", n);
    else printf("  ");
}

int main(){
    char digits[15];
    int w, h;
    while(scanf("%s%d%d", digits, &w, &h) != EOF){
        int length = strlen(digits);
        for(int i = 0; i < h; i++){
            if(i == 0){
                for(int j = 0; j < length; j++){
                    int n = digits[j]-48;
                    if(n != 1 && n != 4)
                        hprint(n, w);
                    else
                        for(int _ = 0; _ < w; _++)
                            printf(" ");
                }
                printf("\n");
            }else if(i == h/2){
                for(int j = 0; j < length; j++){
                    int n = digits[j]-48;
                    if(n!= 0 && n != 1 && n != 7)
                        hprint(n, w);
                    else
                        for(int _ = 0; _ < w; _++)
                            printf(" ");
                }
                printf("\n");
            }else if(i == h-1){
                for(int j = 0; j < length; j++){
                    int n = digits[j]-48;
                    if(n!= 1 && n != 4 && n != 7 && n != 9)
                        hprint(n, w);
                    else
                        for(int _ = 0; _ < w; _++)
                            printf(" ");
                }
            }else if(i < h/2){
                for(int j = 0; j < length; j++)
                    vuprint((digits[j]-48), w);
                printf("\n");
            }else{
                for(int j = 0; j < length; j++)
                    vdprint((digits[j]-48), w);
                printf("\n");
            }
        }
        printf("\n");
    }
}