#include <stdio.h>
#include <stdint.h>
#define max(a, b) (a > b)? a: b
 
 
void solve(int idx, int set[], int n, int sum_of_subset[], int k, int nowmax, int *min){
    if(idx == n){
        if(nowmax < *min) *min = nowmax;
        return;
    }
    for(int i = 0; i < k; i++){
        sum_of_subset[i] += set[idx];
        int tmp = nowmax;
        nowmax = max(nowmax, sum_of_subset[i]);
        if(nowmax < *min) solve(idx+1, set, n, sum_of_subset, k, nowmax, min);
        sum_of_subset[i] -= set[idx];
        nowmax = tmp;
    }
}
 
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int set[15];
    for(int i = 0; i < n; i++) scanf("%d", &set[i]);
    int min = INT32_MAX,  sum_of_subset[15] = {};
    solve(0, set, n, sum_of_subset, k, 0, &min);
    printf("%d\n", min);
}