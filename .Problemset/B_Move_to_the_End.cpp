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

const int N  = 2e5 + 10;
//always check input!!!

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n) , ps(n , 0) , dp(n);
    fo(i , n) cin >> a[i];

    dp[0] = a[0];
    for(int i = 1 ; i < n ; i++){
        dp[i] = max(dp[i - 1] , a[i]);
    }

    ps[n - 1] = a[n - 1];
    for(int i = n - 2 ; i >= 0 ; i--){
        ps[i] += a[i] + ps[i + 1];
    }

    for(int i = n - 1 ; i >= 1 ; i--){
        if(dp[i - 1] > a[i]){
            cout << ps[i] - a[i] + dp[i - 1] << ' ';
        }
        else{
            cout << ps[i] << ' ';
        }
    }
    cout << ps[0] << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow