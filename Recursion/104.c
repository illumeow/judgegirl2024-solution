#include <stdio.h>
#include <stdbool.h>

bool solve(int a, int b, int c, int DA, int DB, int DC, int EA, int EB, int EC, int FA, int FB, int FC){
    if(a < 0 || b < 0 || c < 0) return false;
    if(a == 0 && b == 0 && c == 0) return true;
    
    return (solve(a-DA, b-DB, c-DC, DA, DB, DC, EA, EB, EC, FA, FB, FC) ||
            solve(a-EA, b-EB, c-EC, DA, DB, DC, EA, EB, EC, FA, FB, FC) ||
            solve(a-FA, b-FB, c-FC, DA, DB, DC, EA, EB, EC, FA, FB, FC));
}

void read(int n, int DA, int DB, int DC, int EA, int EB, int EC, int FA, int FB, int FC){
    if(!n) return;
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(solve(a, b, c, DA, DB, DC, EA, EB, EC, FA, FB, FC)) printf("yes\n");
    else printf("no\n");
    read(n-1, DA, DB, DC, EA, EB, EC, FA, FB, FC);
}

int main(){
    /* D = DA*a + DB*b + DC*c 
    given a, b, c
    want to use up all aka a = b = c = 0 */
    int DA, DB, DC, EA, EB, EC, FA, FB, FC;
    scanf("%d%d%d%d%d%d%d%d%d", &DA, &DB, &DC, &EA, &EB, &EC, &FA, &FB, &FC);
    int n;
    scanf("%d", &n);
    read(n, DA, DB, DC, EA, EB, EC, FA, FB, FC);
}