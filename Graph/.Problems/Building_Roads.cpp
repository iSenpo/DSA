#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

const int N = 5e5;
bool seen[N];
vector<int> adj[N];

void DFS(int v){
    seen[v] = true;
    for(int i = 0 ; i < adj[v].size() ; i++){
        if(!seen[adj[v][i]]){
            DFS(adj[v][i]);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    int counter = 0;
    vector<pair<int , int>> ans;
    for(int i = 1 ; i <= n ; i++){
        if(!seen[i]){
            DFS(i);
            counter++;
            ans.push_back({i-1 , i});
        }
    }
    cout << counter << ln;
    for(int i = 0; i < ans.size() ; i++){
        cout << ans[i].first << " " << ans[i].second << ln;
    }
    return 0;
}