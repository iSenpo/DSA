#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n , x;
    cin >> n >> x;
    int v[n] , w[n];
    for(int i = 0 ; i < n ; i++){
        cin >> v[i] >> w[i] ;
    }
    vector<vector<int>> dp(n+1 , vector<int>(n +1 , N));
    for(int i = 0 ; i <= n ; i++){
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            dp[i][j] = dp[i-1][j];
            if(j - v[i] >= 0){
                dp[i][j] = min(dp[i-1][j] , dp[i-1][j-v[i]] + w[i]);
            }
        }
    }
    cout << dp[n][n];
    return 0;
}