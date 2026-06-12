#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> dp(N , 0);
    vector<ll> DP(N , 0);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        dp[a[i]]+= a[i];
    }
    DP[0] = 0;
    DP[1] = dp[1]; 
    for(int i = 2 ; i <= N ; i++){
        DP[i] = max(dp[i] + DP[i-2] , DP[i-1]);
    }
    cout << DP[N];
    return 0;
}