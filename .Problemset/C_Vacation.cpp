#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 1 ; i <= n ; i++)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n;
    cin >> n;
    ll a[n+1][3];
    fo(i , n) cin >> a[i][0] >> a[i][1] >> a[i][2] ;
    vector<vector<ll>> dp( n + 1 , vector<ll>(3 , 0));
    for(int i = 1; i <= n ; i++){
        dp[i][0] = max(dp[i-1][1] , dp[i-1][2]) + a[i][0];
        dp[i][1] = max(dp[i-1][0] , dp[i-1][2]) + a[i][1];
        dp[i][2] = max(dp[i-1][1] , dp[i-1][0]) + a[i][2];
    }
    cout << max(dp[n][0],max(dp[n][1] , dp[n][2]));
    return 0;
}