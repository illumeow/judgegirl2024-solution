#include <stdio.h>
#include <stdint.h>
#include "MorseEncode.h"

#define mxn 1010

int main(){
	char str[mxn];
	scanf("%s", str);

    int n = 0;
	uint64_t encoded_content[mxn];
	MorseEncode(&n, str, encoded_content);

    for(int i=0; i<n; i++)
	    printf("%lu ", encoded_content[i]);
	return 0;
}
