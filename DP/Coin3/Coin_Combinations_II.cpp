#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e7 + 500;
const int MOD = 1e9 + 7;
ll n,x;
vector<int> a;
vector<vector<int>> dp;


//Recursive Solution :
ll solve1(int c ,int x){
    //base :
    if(x == 0){
        return 1;
    }
    if(c > n || x < 0){
        return 0;
    }
    //transition :
    if(dp[c][x] != -1){
        return dp[c][x];
    }
    dp[c][x] = (solve1(c + 1 , x) + solve1(c , x - a[c])) % MOD ;
    return dp[c][x]; 
}

//Iterative Solution :
ll solve2(){
    dp.resize(n + 2 , vector<int>(x + 1, 0));
    for(int i = 0 ; i < n + 1 ; i++){
        dp[i][0] = 1;
    }
    for(int i = n ; i >= 1 ; i--){
        for(int k = 1 ; k <= x ;k++){
            int skipping = dp[i + 1][k];
            int picking = 0;
            if(a[i] <= k){
                picking = dp[i][k - a[i]];
            }
            dp[i][k] = (skipping + picking) % MOD;
        }
    }
    return dp[1][x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x; 
    a.resize(n + 2);
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    dp.resize(n + 1 , vector<int>(x + 1, -1));
    for(int i = 0 ; i < n + 1 ; i++){
        dp[i][0] = 1;
    }
    cout << solve1(1 , x)<<endl;
    //cout << solve2();
    return 0;
}