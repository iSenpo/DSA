#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define pll pair<ll , ll>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define	set_dec(x) cout << fixed << setprecision(x);
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;
const int N  = 3e5 + 10;
const int INF = 2e9 + 100;
const int MIN = -2e9 - 100;
//always check input!!!

vector<vector<int>> adj;
vector<ll> dp , p , ans;

void dfs(int v , int par){
    int cnt = 0;
    for(int i : adj[v]){
        if(i != par){
            dfs(i , v);
            dp[v] += dp[i];
            cnt++;
        }
    }
    dp[v] = (dp[v] + (cnt * 2)) % MOD;
}
void dfs2(int v){
    if(v == 1){
        ans[v] = (dp[v] + 1)%MOD;
    }
    else{
        ans[v] = (dp[v] + ans[p[v]] + 1)%MOD;
    }
    for(int i : adj[v]){
        if(i != p[v]){
            dfs2(i);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    adj = vector<vector<int>>(n + 10 , vector<int>());
    p = vector<ll>(n + 5 , 0);
    dp = vector<ll>(n + 5 , 0);
    ans = vector<ll>(n + 5 , 0);
    fo(i , n){
        int l , r;
        cin >> l >> r;
        if(l){
            adj[l].push_back(i + 1);
            adj[i + 1].push_back(l);
            p[l] = i + 1;
        }
        if(r){
            adj[i + 1].push_back(r);
            adj[r].push_back(i + 1);
            p[r] = i + 1;
        }
    }
    adj[1].push_back(0);
    adj[0].push_back(1);
    p[0] = -1;
    dfs(0 , -1);
    dfs2(1);
    for(int i = 1 ; i <= n ; i++){
        cout << ans[i] << ' ';
    }
    cout << ln ;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
