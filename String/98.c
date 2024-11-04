#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLENGTH 70

typedef struct {
    char name[MAXLENGTH];
    int ingredient_num;
    char ingredient[10][MAXLENGTH];
} Food;

int cmp(const void *A, const void *B){
    char const *a = (char const *)A;
    char const *b = (char const *)B;
    return strcmp(a, b);
}

int main(){
    int n;
    scanf("%d", &n);
    Food foods[105];
    for(int i = 0; i < n; i++){
        scanf("%s", foods[i].name);
        scanf("%d", &foods[i].ingredient_num);
        for(int j = 0; j < foods[i].ingredient_num; j++)
            scanf("%s", foods[i].ingredient[j]);
    }
    int m;
    scanf("%d", &m);
    char f1[MAXLENGTH], f2[MAXLENGTH];
    for(int i = 0; i < m; i++){
        scanf("%s%s", f1, f2);
        int i1, i2;
        for(int j = 0; j < n; j++)
            if(strcmp(f1, foods[j].name) == 0)
                i1 = j;
        for(int j = 0; j < n; j++)
            if(strcmp(f2, foods[j].name) == 0)
                i2 = j;
        char ans[10][MAXLENGTH];
        int indx = 0;
        for(int j = 0; j < foods[i1].ingredient_num; j++){
            for(int k = 0; k < foods[i2].ingredient_num; k++){
                if(strcmp(foods[i1].ingredient[j], foods[i2].ingredient[k]) == 0)
                    strcpy(ans[indx++], foods[i1].ingredient[j]);
            }
        }
        
        qsort(ans, indx, sizeof(char)*MAXLENGTH, cmp);

        if(indx == 0) printf("nothing\n");
        for(int j = 0; j < indx; j++)
            printf("%s%c", ans[j], " \n"[j==indx-1]);
    }
}