#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
#define all(x) (x).begin(),(x).end()
ll MOD = 1e9 + 7;
const int N = 1e6;
vector<vector<ll>> dp(N + 1 , vector<ll>(6 , 0));
inline int in(){
    int x;
    cin >> x;
    return x;
}
//Recursive Solution:
ll solve(int n , int i)
{
    //base :
    if(n == 1){
        return 1;
    }
    //transition :
    if(dp[n][i] != 0){
        return dp[n][i];
    }
    ll ans = 0;
    if(i == 0 || i == 2){
        ans = (ans + solve(n-1 , 0))%MOD;
        ans = (ans + solve(n-1 , 1))%MOD;   
        ans = (ans + solve(n-1 , 2))%MOD;
    }
    if(i == 1 || i == 3 || i == 4 || i == 5){
        ans = (ans + solve(n-1 , 1))%MOD;    
        ans = (ans + solve(n-1 , 2))%MOD;
        ans = (ans + solve(n-1 , 3))%MOD;   
        ans = (ans + solve(n-1 , 4))%MOD;   
        ans = (ans + solve(n-1 , 5))%MOD;   
    }
    return dp[n][i] = ans;
}
//Iterative Solution:
ll solve2(){
    //base:
    for(int i = 0 ; i < 6 ; i++){
        dp[1][i] = 1;
    }
    //transition:
    for(int i = 2 ; i <= N ; i++){
        for(int j = 0 ; j < 6 ; j++){
            if(j == 0 || j == 2){
                dp[i][j] = (dp[i][j] + dp[i-1][0] )%MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][1] )%MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][2] )%MOD;
            }
            if(j == 1 || j == 3 || j == 4 || j == 5){
                dp[i][j] = (dp[i][j] + dp[i-1][1] )%MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][2] )%MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][3] )%MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][4] )%MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][5] )%MOD;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = in();
    solve2();
    while(t--){
        int n = in();
        ll ans = (dp[n][1]+ dp[n][2])%MOD;
        cout << ans << ln;
    }
    return 0;
}