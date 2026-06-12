#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int N  = 1e5 + 500;

int n , m;
vector<int> adj[N];
int h[N];
bool seen[N];
vector<pair<int , int>> edges;

void input(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
}
int dfs(int v ,int height , int par){
    seen[v] = true;
    h[v] = height;
    int min_height = height;
    for(int i = 0 ; i < adj[v].size() ; i++){
        if(seen[adj[v][i]]){
            if(adj[v][i] != par){
                min_height = min(min_height , h[adj[v][i]]);
            }
        }
        else{
            int child = dfs(adj[v][i] , height + 1 , v);
            if(child > height){
                edges.push_back({v , adj[v][i]});
            }
            min_height = min(min_height , child);
        }
    }
    return min_height;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    input();
    cout <<"~~~~~~~~~~~~~~~~~~\n";
    
    for(int i = 0 ; i < n ; i++)
        if(!seen[i])
            dfs(i , 0 , -1);
    for(int i = 0 ; i < edges.size() ; i++)
        cout << edges[i].first << ' ' << edges[i].second << ln;
    
    return 0;
}