#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 1 ; i <= n ; i++)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n , x;
    cin >> n >> x;
    int a[n],w[n];
    fo(i , n) cin >> a[i] >> w[i];

    vector<vector<ll>> dp(n + 1 , vector<ll>(x + 1 , 0));

    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            if(j - a[i] >= 0){
                dp[i][j] = max(dp[i-1][j] , dp[i-1][j-a[i]] + w[i]);
            }
        }
    }
    cout << dp[n][x];
    return 0;
}