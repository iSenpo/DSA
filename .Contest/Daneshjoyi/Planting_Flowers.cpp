#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define mt(x , y , z) make_tuple(x , y , z)

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;

const int N  = 1e3 + 10;
//always check input!!!
vector<vector<vector<int>>> dp(N , vector<vector<int>>(N , vector<int>(2 , -1)));
int n , m;
ll dq(int i , int j , int col){
    if(i >= n || j >= m){
        return 0;
    }
    if(i == n - 1 && j == m - 1){
        return 1;
    }  
    if(dp[i][j][col] != -1){
        return dp[i][j][col];
    }
    ll ans = 0;
    if(col == 1){
        ans += (dq(i + 1 , j , 0) + dq(i , j + 1 , 0)) % MOD;
    }
    else{
        ans += (dq(i + 1 , j , 1) + dq(i , j + 1 , 1)) % MOD;
    }
    ans += (dq(i + 1 , j , 0) + dq(i , j + 1 , 1)) % MOD;
    ans += (dq(i + 1 , j , 1) + dq(i , j + 1 , 0)) % MOD;
    dp[i][j][col] = ans;
    return dp[i][j][col];
}
void solve()
{
    cin >> n >> m;
    ll ans = (dq(0 , 0 , 0) + dq(0 , 0 , 1)) % MOD;
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow