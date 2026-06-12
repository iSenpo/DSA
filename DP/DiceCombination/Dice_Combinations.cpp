//https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e6 + 500;
const int MOD = 1e9 + 7;
vector<unsigned long long> dp(N , -1);

//Recursive Solution :
unsigned long long solve1(ll n){
    //base : 
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    //transition :
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = 0;
    for(int i = 1; i <= 6 ; i++){
        dp[n] = (dp[n] + solve1(n - i)) % MOD ;
    }
    return dp[n];
}

//Iterative Solution:
unsigned long long solve2(ll n){
    //base :
    dp[0] = 1;

    //transition :
    for(int i = 1 ; i <= n; i++){
        dp[i] = 0;
        for(int j = 1; j <= 6 ; j++){
            if(j <= i){
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    return dp[n];
}
//Iterative Solution 2:
unsigned long long solve3(ll n){
    //base :
    dp[n] = 1;

    //transition :
    for(int i = n-1 ; i >= 0; i--){
        dp[i] = 0;
        for(int j = 1; j <= 6 ; j++){
            if(j <= n - i){
                dp[i] = (dp[i] + dp[i + j]) % MOD;
            }
        }
    }
    return dp[0];
}
int main(){
    ll n;
    cin >> n;
    cout << solve1(n) <<"\n" << solve2(n) << "\n" << solve3(n);
    return 0;
}