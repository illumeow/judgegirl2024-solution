#include <stdio.h>
#include <stdint.h>

void solve(int idx, uint64_t set[], int n, uint64_t sum_of_sq, uint64_t sum_of_subset[], int k, uint64_t *min){
    if(sum_of_sq >= *min) return;
    if(idx == n){
        if(sum_of_sq < *min) *min = sum_of_sq;
        return;
    }

    for(int i = 0; i < k; i++){
        sum_of_sq -= sum_of_subset[i]*sum_of_subset[i];
        sum_of_subset[i] += set[idx];
        sum_of_sq += sum_of_subset[i]*sum_of_subset[i];
        if(sum_of_sq < *min) solve(idx+1, set, n, sum_of_sq, sum_of_subset, k, min);
        sum_of_sq -= sum_of_subset[i]*sum_of_subset[i];
        sum_of_subset[i] -= set[idx];
        sum_of_sq += sum_of_subset[i]*sum_of_subset[i];
    }
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    uint64_t set[20];
    for(int i = 0; i < n; i++) scanf("%llu", &set[i]);
    int group[20];
    for(int i = 0; i < n; i++) group[i] = -1;
    uint64_t min = UINT64_MAX, sum_of_subset[10] = {};
    solve(0, set, n, 0, sum_of_subset, k, &min);
    printf("%llu\n", min);
}