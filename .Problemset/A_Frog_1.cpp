#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n ;
    cin >> n;
    int h[n];
    fo(i , n) cin >> h[i];
    vector<ll> dp(n + 5 , 0);
    
    for(int i = n - 2; i >= 0 ; i--){
        dp[i] = min(abs(h[i] - h[i + 1]) + dp[i + 1] , abs(h[i] - h[i + 2]) + dp[i + 2]);
    }
    cout << dp[0];
    return 0;
}