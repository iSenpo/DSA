#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'

const int N = 2e5 + 500 , lg = 22;
int n , q;
vector<int> adj[N];
int par[N][lg];
int h[N];

int lca(int v , int u){
    if(h[v] < h[u]){
        swap(v , u);
    }
    int x = h[v] - h[u];
    for(int i = lg - 1 ; i >= 0 ; i--){
        if(h[v] - (1 << i) >= h[u]){
            v = par[v][i];
        }
    }
    if(v == u){
        return v;
    }
    for(int i = lg - 1 ; i >= 0 ; i--){
        if(par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[v][0];
}
int dis(int v , int u){
    return h[v] + h[u] - 2*(h[lca(v , u)]);
}
void dfs(int v ,int p = -1){
    par[v][0] = p;
    for(int i = 1 ; i < lg ; i++){
        if(par[v][i - 1] != -1){
            par[v][i] = par[par[v][i - 1]][i - 1];
        }
        else{
            break;
        }
    }
    for(int i : adj[v]){
        if(i != p){
            h[i] = h[v] + 1;
            dfs(i , v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    cin >> n >> q;
    memset(par , -1 , sizeof par);
    for(int i = 0 ; i < n - 1 ; i++){
        int v , u;
        cin >> v >> u;
        v--;
        u--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(0);
    while(q--){
        int v , u;
        cin >> v >> u;
        v--;
        u--;
        cout << dis(v , u) << ln;
    }
    return 0;
}
/*
Input :
7 10
1 2
2 3
2 4
1 5
5 6
5 7

1 2
1 3
1 4
3 4
1 5
1 6
1 7
6 7
6 4
7 3

Output :
1
2
2
2
1
2
2
2
4
4
*/