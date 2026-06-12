#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

const int N  = 5e3 + 10;
bool mark[N];
vector<int> adj[N];
stack<int> stk;

void dfs(int v){
    if(!mark[v]){
        mark[v] = true;
        for(int i : adj[v])
            dfs(i);
    }
}

void dfs2(int v){
    if(!mark[v]){
        mark[v] = true;
        stk.push(v);
        for(int i : adj[v])
            dfs(i);
    }
}
void solve()
{
    int n , m  , s;
    cin >> n >> m >> s;
    s--;
    fo(i , m){
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        adj[v].pb(u);
    }
    dfs(s);
    for(int i = 0 ; i < n ; ++i){
        if(!mark[i]){
            dfs2(i);
        }
    }
    ll ans = 0;
    memset(mark , false , sizeof mark);
    while(!stk.empty()){
        int v = stk.top();
        stk.pop();
        if(!mark[v]){
            dfs(v);
            ans++;
        }
    }
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}