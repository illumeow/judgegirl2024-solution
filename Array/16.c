#include <stdio.h>

int main(){
    int num[1005] = {}, odd[1005] = {}, even[1005] = {};
    int n, oddi = 0, eveni = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);

    for(int i = 0; i < n; i++){
        if(num[i] & 1){
            odd[oddi] = num[i];
            oddi++;
        }else{
            even[eveni] = num[i];
            eveni++;
        }
    }

    for(int i = 0; i < oddi - 1; i++) printf("%d ", odd[i]);
    printf("%d\n", odd[oddi - 1]);
    for(int i = 0; i < eveni - 1; i++) printf("%d ", even[i]);
    printf("%d", even[eveni - 1]);
}