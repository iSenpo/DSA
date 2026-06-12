#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e6 + 500;
const int MOD = 1e9 + 7;
ll n,x;
ll a[N];
vector<ll> dp(N , -1);
//Recursive Solution :
ll solve1(ll x){
    //base :
    if(x == 0){
        return 1;
    }
    if(x < 0 || n == 0){
        return 0;
    }
    //transition :
    if(dp[x] != -1){
        return dp[x];
    }
    dp[x] = 0;
    for(ll i = 0; i < n ; i++){
        dp[x] = (dp[x] + solve1(x - a[i])) % MOD;
    }
    return dp[x];
}

//Iterative Solution :
ll solve2(ll x){
    //base :
    dp[0] = 1;

    //transition :
    for(int i = 1 ; i <= x ; i++){
        dp[i] = 0;
        for(int j = 0; j < n; j++){
            if(a[j] <= i){
                dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
            }
        }
    }
    return dp[x];
}
int main(){
    cin >> n >> x; 
    for(ll i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    cout << solve1(x) << "\n" << solve2(x);
    return 0;
}