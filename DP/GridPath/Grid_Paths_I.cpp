#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;
int MOD = 1e9 + 7;
vector<vector<char>> s;
vector<vector<bool>> trap;
vector<vector<ll>> dp;

//Recursive Soliution :
ll solve1(int i ,int j){
    //base :
    if(i == 0 && j == 0 && dp[i][j] != 0){
        return 1;
    }
    if(i < 0 || j < 0){
        return 0;
    }
    //transition :
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    dp[i][j] = (solve1(i-1 , j) + solve1(i , j-1)) % MOD;
    return dp[i][j];
}

//Iterative Solution :

ll solve2(int n){
    //base : 
    dp[0][0] = 0;

    //transition :
    for(int i = 1; i < n ; i++){
        for(int j = 1 ; j < n - i ; j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    return dp[n-1][n-1];
}
int main(){
    int n;
    cin >> n;
    s.resize(n , vector<char>(n));
    dp.resize(n,vector<ll>(n , -1));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> s[i][j];
            if(s[i][j] == '*'){
                dp[i][j] = 0;
            }
        }
    }
    cout << solve1(n-1 , n-1) << "  " << solve2(n);
    return 0;
}