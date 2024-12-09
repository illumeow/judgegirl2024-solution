#include <stdio.h>

int main(){
    char filename[205] = {};
    scanf("%s", filename);
    FILE *fp = fopen(filename, "rb");
    int n;
    fread(&n, sizeof(int), 1, fp);
    int cnt[65540] = {};
    for(int i = 0; i < n; i++){
        short num;
        fread(&num, sizeof(short), 1, fp);
        cnt[num+32768]++;
    }
    
    int maxnum, maxcnt = 0;
    for(int i = 65539; i >= 0; i--)
        if(cnt[i] > maxcnt)
            maxcnt = cnt[i], maxnum = i-32768;
    printf("%d\n%d\n", maxnum, maxcnt);
}