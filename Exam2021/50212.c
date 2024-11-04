#include <stdio.h>
typedef unsigned int ui;

int num_of_1(ui n){
    int ret = 0;
    while(n > 0){
        ret += (n & 1);
        n >>= 1;
    }
    return ret;
}

void num2arr(ui n, short arr[32]){
    for(int i = 31; i >= 0; i--){
        arr[i] = (n & 1);
        n >>= 1;
    }
}

ui arr2num(short arr[32]){
    ui ret = 0, n = 1;
    for(int i = 31; i >= 0; i--){
        ret += arr[i]*n;
        n += n;
    }
    return ret;
}

void printArr(short arr[32]){
    for(int i = 0; i < 32; i++){
        printf("%d", arr[i]);
        if(i % 4 == 3) printf(" ");
    }
    printf("\n");
}

void solve(short arr[], int n){
    int mid = n / 2;
}

int main(){
    ui n;
    scanf("%u", &n);
    short numArr[32];
    num2arr(n, numArr);
    #ifdef INPUT
    printArr(numArr);
    printf("%u\n", arr2num(numArr));
    #endif

}