#include <stdio.h>

int in_board(int x, int y){
    return (0 <= x && x <= 2 && 0 <= y && y <= 2);
}
int check(int board[3][3], int tar){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == tar && board[i][1] == tar && board[i][2] == tar) return 1;
        if(board[0][i] == tar && board[1][i] == tar && board[2][i] == tar) return 1;
    }
    if(board[0][0] == tar && board[1][1] == tar && board[2][2] == tar) return 1;
    if(board[2][0] == tar && board[1][1] == tar && board[0][2] == tar) return 1;
    return 0;
}

int main(){
    int N;
    scanf("%d", &N);
    int board[3][3] = {};

    int player = 1;
    while(N--){
        int x, y;
        scanf("%d%d", &x, &y);
        if(!in_board(x, y)) continue;
        if(board[x][y]) continue;
        board[x][y] = player;
        player *= -1;

        #ifdef DEBUG
        printf("==========\nN: %d player: %d\nmove: (%d, %d)\n", N, -player, x, y);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        #endif
    }
    if(check(board, 1)) printf("Black wins.");
    else if(check(board, -1)) printf("White wins.");
    else printf("There is a draw.");
}