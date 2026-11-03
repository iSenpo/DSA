#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
int MOD = 1e9 + 7;
const ll N  = 2e17;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n , k;
    cin >> n >> k;

    vector<int> h(n + 105 , 0);
    vector<ll> dp(n + 105 ,N);
    fo(i , n) cin >> h[i];

    dp[n-1] = dp[n] = 0;
    for(int i = n-1 ; i >= 0 ; i--){
        for(int j = 1 ; j <= k && i + j < n ; j++){
                dp[i] = min(dp[i] , abs(h[i] - h[i+j]) + dp[i+j]);
        }
    }
    cout << dp[0];
    return 0;
}