#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for(int i = 1 ; i <= n ; i++)
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];

void solve()
{

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m;
    cin >> n >> m;
    fo(i , n) cin >> arr[i];

    //dp base :
    vector<vector<ll>> dp(n + 1 , vector<ll>(m + 2 , 0));
    if(arr[1] == 0){
        for(int i = 1 ; i <= m ; i++){
            dp[1][i] = 1;
        }
    }
    else{
        dp[1][arr[1]] = 1;
    }
    for (int i = 2 ; i <= n ; i++){
        if(arr[i] != 0){
            dp[i][arr[i]] = (dp[i -1][arr[i]-1] + dp[i-1][arr[i]] + dp[i-1][arr[i]+1]) % MOD;
            continue;
        }
        for (int j = 1 ; j <= m ; j++){
            dp[i][j] = (dp[i -1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
        }
    }
    int sum = 0;
    for(int i = 1 ; i <= m ; i++){
            sum = (sum + dp[n][i]) % MOD;
    }
    cout << sum ;
    return 0;
}