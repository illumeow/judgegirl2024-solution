#include <stdio.h>
#define ll long long

ll gcd(ll a, ll b){
    ll i = a*(a > b) + b*(a <= b);
    ll j = b*(a > b) + a*(a <= b);
    while(i % j != 0){
        ll r = i % j;
        i = j; 
        j = r;
    }
    return j;
}

ll lcm(ll a, ll b){
    // printf("%d %d: %d\n", a, b, gcd(a, b));
    return (a*b)/gcd(a, b);
}

int main(){
    ll a, b, c, d;
    while(scanf("%lld%lld%lld%lld", &a, &b, &c, &d) != EOF)
        printf("%lld\n", (lcm(lcm(a, b), lcm(c, d)))/a);
}