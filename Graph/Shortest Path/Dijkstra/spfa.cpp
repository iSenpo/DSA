#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e18;
const int N = 1e5 + 10;

vector<pair<int,ll>> adj[N];
ll d[N], f[N];
int par[N];

void solve()
{
    int n, m, s = 1;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        adj[i].clear();
        d[i] = INF;
        f[i] = INF;
        par[i] = -1;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    f[s] = 0;
    for(int i = 1; i <= n; i++){
        int v = -1;
        ll h = INF;
        for(int j = 1; j <= n; j++){
            if(d[j] == INF && f[j] < h){
                h = f[j];
                v = j;
            }
        }
        if(v == -1) break;
        d[v] = h;
        for(auto p : adj[v]){
        int to = p.first;
        ll w = p.second;

        if(d[to] == INF){
            if(f[to] > d[v] + w){
                f[to] = d[v] + w;
                par[to] = v;
            }
        }
        }
    }
    if(d[n] == INF){
        cout << -1;
        return;
    }
    vector<int> path;
    for(int v = n; v != -1; v = par[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    for(int x : path)
        cout << x << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}