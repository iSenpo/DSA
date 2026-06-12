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
const int N  = 2e5 + 10;
const int INF = 2e9 + 100;
const int MIN = -2e9 - 100;
//always check input!!!

vector<ll> cnt;
vector<vector<ll>> adj;
void dfs(int v , int par){
    if(adj[v].size() == 1 && adj[v][0] == par){
        cnt[v] = 1;
        return;
    }
    for(int i : adj[v]){
        if(i != par){
            dfs(i , v);
            cnt[v] += cnt[i];
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    adj.assign(n + 10 , vector<ll>());
    cnt.assign(n + 10 , 0);
    fo(i , n - 1){
        int v , u;
        cin >> v >> u;
        u--;
        v--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(0 , -1);
    int q;
    cin >> q;
    while(q--){
        int x , y;
        cin >> x >> y;
        x--;
        y--;
        ll ans = cnt[x] * (1LL) * cnt[y];
        cout << ans << ln;
    }
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
