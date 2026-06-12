#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL);
#define ll long long
#define pii pair<int , int>
#define ln '\n'
const int N  = 2e5 + 10;

int n , m;
vector<int> adj[N];
bool mark[N];
int h[N] , up[N];
vector<int> CutVertex;

void dfs(int v , int par = -1){
    mark[v] = true;
    up[v] = h[v];
    int child_cnt = 0; // is root a cut vertex?
    bool is_cut = false;
    for(int i : adj[v]){
        if(i == par){
            continue;
        }
        if(mark[i]){
            up[v] = min(up[v] , h[i]);
        }
        else{
            h[i] = h[v] + 1;
            dfs(i , v);
            child_cnt++;
            up[v] = min(up[v] , up[i]);
            if(up[i] >= h[v]){
                is_cut = true;
            }
        }
    }
    if(par == -1){
        is_cut = child_cnt > 1;
    }
    if(is_cut){
        CutVertex.push_back(v);
    }
}
int main(){
    fastio;
    cin >> n >> m;
    int v , u;
    for(int i = 0 ; i < m ; i++){
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    //
    dfs(1);
    //output :
    for(int i : CutVertex){
        cout << i << ln;
    }
    return 0;
}
