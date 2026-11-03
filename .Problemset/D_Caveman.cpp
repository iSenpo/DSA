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
vector<int> adj[N];
vector<bool> mark(N);
void dfs(int v){
    mark[v] = 1;
    for(int u : adj[v]){
        if(!mark[u]){
            mark[u] = 1;
            dfs(u);
        }
    }
}
void solve()
{
    ll n , m;
    cin >> n >> m;
    fo(i , n + 100){
        adj[i].clear();
        mark[i] = false;
    }
    fo(i , m){
        int v , u;
        cin >> v >> u;
        v--;
        u--;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(0);
    fo(i , n){
        if(!mark[i]){
            cout << "Brain Melt\n";
            return;
        }
    }
    int cnt = 0;
    fo(i , n){
        if(adj[i].size() >= 2) cnt++;
    }
    if(cnt == 0){
        cout << 1 << ln;
    }
    else if(cnt == 1){
        cout << 2 << ln;
    }
    else{
        cout << "Many\n";
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
