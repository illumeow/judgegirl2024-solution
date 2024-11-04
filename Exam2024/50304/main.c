#include <stdio.h>
#include <stdint.h>
#include "MorseDecode.h"
 
#define mxn 1010
 
int main() {
    int n;
    scanf("%d", &n);
 
    uint64_t encoded_content[mxn];
    for (int i = 0; i < n; i++)
        scanf("%llu", &encoded_content[i]);
 
    char ans[mxn];
    MorseDecode(n, encoded_content, ans);
 
    printf("%s\n", ans);
    return 0;
}