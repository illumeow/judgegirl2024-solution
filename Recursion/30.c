#include <stdio.h>
#include <stdbool.h>

bool in(int x, int y, int r, int c){
    return (0 <= x && x < r && 0 <= y && y < c);
}

void solve(int x, int y, int matrix[][15], int r, int c, int *ans){
    if(matrix[x][y] == 0 || !in(x, y, r ,c)) return;
    if(x == 0 && y == c-1) (*ans)++;
    solve(x-1, y, matrix, r, c, ans);
    solve(x, y+1, matrix, r, c, ans);
}

int main(){
    int r, c;
    scanf("%d%d", &r, &c);
    int matrix[15][15];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);
    int ans = 0;
    solve(r-1, 0, matrix, r, c, &ans);
    printf("%d\n", ans);
}