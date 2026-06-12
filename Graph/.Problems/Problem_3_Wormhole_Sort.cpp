#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

const int INF = 1e9;
const int N  = 1e5 + 500;
vector<pair<int , int>> adj[N];
bool seen[N];
bool pos[N];

int dfs(int v , int u){
    seen[v] = true;
    int cost = INF;
    int cost2 = INF;
    for(int i = 0 ; i < adj[v].size() ; i++){
        if(!seen[adj[v][i].first]){
            if(adj[v][i].first == u){
                cost = min(cost , adj[v][i].second);
            }
        }
    }
    for(int i = 0 ; i < adj[v].size() ; i++){
        if(!seen[adj[v][i].first]){
            if(adj[v][i].first != u){
                cost2 = min(cost , dfs(adj[v][i].first , u));
            }
        }
    }
    return cost;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n , m;
    cin >> n >> m;
    int p[n + 1];
    for(int i = 1 ; i <= n ; i++){
        cin >> p[i];
        if(i == p[i]){
            pos[i] = true; 
        }
    }
    int a , b , w;
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b >> w;
        adj[a].push_back({b , w});
        adj[b].push_back({a , w});
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++) {
        
    }
    return 0;
}