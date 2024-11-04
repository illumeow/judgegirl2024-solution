#include <stdio.h>
#define MAXN 15

typedef long long ll;
typedef struct Pair{
    ll x, y;
} Pair;

Pair make_pair(ll x, ll y){
    Pair ret;
    ret.x = x;
    ret.y = y;
    return ret;
}

ll gcd(ll a, ll b){
    ll i = (a>b)?a:b;
    ll j = (a>b)?b:a;
    while(i % j != 0){
        ll r = i % j;
        i = j;
        j = r;
    }
    return j;
}

Pair reduce_frac(Pair frac){
    if(frac.x == 0) return make_pair(0, 1);
    int g = gcd(frac.x, frac.y);
    return make_pair(frac.x/g, frac.y/g);
}

Pair add_frac(Pair a, Pair b){
    Pair ret = {a.x*b.y+a.y*b.x, a.y*b.y};
    return reduce_frac(ret);
}

Pair mul_frac(Pair a, Pair b){
    Pair ret = {a.x*b.x, a.y*b.y};
    return reduce_frac(ret);
}

void solve(int i, int j, int n, Pair parent_percentage, ll (*left)[MAXN][MAXN], ll (*right)[MAXN][MAXN], Pair (*ans)[MAXN+1]){
    if(i == n){
        (*ans)[j] = add_frac(parent_percentage, (*ans)[j]);
        return;
    }
    Pair left_percentage = make_pair((*left)[i][j], (*left)[i][j]+(*right)[i][j]);
    Pair right_percentage = make_pair((*right)[i][j], (*left)[i][j]+(*right)[i][j]);

    solve(i+1, j, n, mul_frac(left_percentage, parent_percentage), left, right, ans);
    solve(i+1, j+1, n, mul_frac(right_percentage, parent_percentage), left, right, ans);
}

int main(){
    int n;  // num of rows
    scanf("%d", &n);
    ll left[MAXN][MAXN], right[MAXN][MAXN];
    Pair ans[MAXN+1];
    for(int i = 0; i <= n; i++){
        ans[i].x = 0;
        ans[i].y = 1;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            scanf("%lld%lld", &left[i][j], &right[i][j]);

    solve(0, 0, n, make_pair(1, 1), &left, &right, &ans);

    for(int i = 0; i < n; i++)
        printf("%lld/%lld\n", ans[i].x, ans[i].y);
    printf("%lld/%lld\n", ans[n].x, ans[n].y);
}