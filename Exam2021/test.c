#include <stdio.h>

int main(){
    int n;
    int arr[1005][1005] = {};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    // sum of row
    for(int i = 0; i < n; i++){
        int rowSum = 0;
        for(int j = 0; j < n; j++){
            rowSum += arr[i][j];
        }
        printf("%d\n", rowSum);
    }

    // sum of column
    for(int i = 0; i < n; i++){
        int colSum = 0;
        for(int j = 0; j < n; j++){
            colSum += arr[j][i];
        }
        printf("%d\n", colSum);
    }

    // sum of diagonal
    int mainDiagSum = 0;
    for(int i = 0; i < n; i++){
        mainDiagSum += arr[i][i];
    }
    printf("%d\n", mainDiagSum);

    int antiDiagSum = 0;
    for(int i = 0; i < n; i++){
        antiDiagSum += arr[i][(n-1)-i];
    }
    printf("%d\n", antiDiagSum);
}