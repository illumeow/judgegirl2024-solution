#include <stdio.h>
#include <stdint.h>

void solve(int idx, int n, int choosed[], int num_of_choosed, int friends[][2], int m, int covered[], int num_of_covered, int *min, int best[]){
    #ifdef DEBUG
    printf("%d: ", idx);
    for(int i = 0; i < n; i++){
        if(choosed[i] == -1) break;
        printf("%d ", choosed[i]);
    }
    printf(" | ");
    for(int i = 0; i < m; i++)
        printf("%d ", covered[i]);
    printf("\n");
    #endif

    if(num_of_covered == m){
        if(num_of_choosed < *min){
            #ifdef DEBUG
            printf("update, num = %d\n", num_of_choosed);
            #endif
            *min = num_of_choosed;
            for(int i = 0; i < num_of_choosed; i++){
                best[i] = choosed[i];
            }
            best[num_of_choosed] = -1;
        }
        return;
    }
    if(idx == n) return;
    
    // choose
    choosed[num_of_choosed] = idx;
    for(int i = 0; i < m; i++){
        if(idx == friends[i][0] || idx == friends[i][1]){
            if(covered[i] == 0) num_of_covered++;
            covered[i]++;
        }
    }
    if(num_of_choosed+1 < *min) solve(idx+1, n, choosed, num_of_choosed+1, friends, m, covered, num_of_covered, min, best);
    // reset
    for(int i = 0; i < m; i++){
        if(idx == friends[i][0] || idx == friends[i][1]){
            covered[i]--;
            if(covered[i] == 0) num_of_covered--;
        }
    }
    choosed[num_of_choosed] = -1;
    // not choose
    solve(idx+1, n, choosed, num_of_choosed, friends, m, covered, num_of_covered, min, best);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    // friends is an adjacency matrix
    int friends[4100][2] = {{}};
    for(int i = 0; i < m; i++)
        scanf("%d%d", &friends[i][0], &friends[i][1]);
    

    int choosed[65] = {}, covered[4100] = {}, min = INT32_MAX, best[65];
    for(int i = 0; i < 65; i++){
        choosed[i] = best[i] = -1;
    }
    solve(0, n, choosed, 0, friends, m, covered, 0, &min, best);
    for(int i = 0; i < n; i++){
        if(best[i] == -1) break;
        printf("%d\n", best[i]);
    }
}