#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;

const int N  = 2e5 + 500;
vector<int> adj[N];
bool mark[N];
bool cycle;

inline int in(){
    int x;
    cin >> x;
    return x;
}
void dfs(int v){
    mark[v] = true;
    if(adj[v].size() != 2){
        cycle = false;
    }
    for(int i = 0 ; i < sz(adj[v]) ; ++i){
        if(!mark[adj[v][i]]){
            dfs(adj[v][i]);
        }
    }
}
void solve()
{
    int n = in();
    int m = in();
    fo(i , m){
        int v , u;
        cin >> v >> u;
        v--;
        u--;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    int ans = 0;
    fo(i , n){
        if(!mark[i]){
            cycle = true;
            dfs(i);
            if(cycle){
                ans++;
            }
        }
    }
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //t = in();
    while(t--){
        solve();
    }
    return 0;
}