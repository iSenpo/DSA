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

vector<int> par;
vector<int> dp;


void solve()
{
    int n;
    cin >> n;
    par.clear();
    dp.clear();
    par.resize(n + 1);
    dp.resize(n + 1 , -1);
    int a[n];
    fo(i , n) cin >> a[i];
    fo(i , n){
        par[i + 1] = a[i];
    }
    for(int i = 1 ; i <= n ; i++){
        if(dp[i] != -1){
            continue;
        }
        int k = i;
        int cnt = 1;
        while(par[k] != i){
            k = par[k];
            cnt++;
            if(dp[k] != -1){
                dp[i] = dp[k];
                break;
            }
        }
        if(dp[i] == -1){
            dp[i] = cnt;
        }
        int x = par[i];
        while(x != i){
            dp[x] = dp[i];
            x = par[x];
        }
    }
    for(int i = 1 ; i <= n ; i++){
        cout << dp[i] << ' ';
    }
    cout << ln;
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