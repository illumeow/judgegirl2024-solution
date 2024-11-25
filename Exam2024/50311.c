#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
 
bool is_sd(bool choosed[], bool adj[][20], int n){
    for(int i = 0; i < n; i++){
        bool pass = false;
        for(int j = 0; j < n && !pass; j++)
            if(j != i && adj[i][j] && choosed[j]) pass = true;
        if(!pass) return false;
    }
    return true;
}
 
void solve(int idx, int n, bool choosed[], int num_of_choosed, bool adj[][20], int *min, bool ans[]){
    if(idx == n){
        if(num_of_choosed < *min && is_sd(choosed, adj, n)){
            *min = num_of_choosed;
            for(int i = 0; i < n; i++)
                ans[i] = choosed[i];
        }
        return;
    }
    /* choose */
    choosed[idx] = true;
    solve(idx+1, n, choosed, num_of_choosed+1, adj, min, ans);
    /* reset */
    choosed[idx] = false;
    /* not choosed */
    solve(idx+1, n, choosed, num_of_choosed, adj, min, ans);
}
 
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    bool adj[20][20] = {};
    for(int i = 0; i < 20; i++) adj[i][i] = true;
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a-1][b-1] = adj[b-1][a-1] = true;
    }
    int min = INT32_MAX;
    bool choosed[20] = {}, ans[20] = {};
    solve(0, n, choosed, 0, adj, &min, ans);
    printf("%d\n", min);
    for(int i = 0; i < n; i++)
        if(ans[i]) printf("%d ", i+1);
    printf("\n");
}