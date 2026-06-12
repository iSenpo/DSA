#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'

const int N = 1e6 + 10;
vector<int> adj[N];
vector<int> sources;
vector<int> sorted;
int d[N];

void solve(){
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int v , u;
        cin >> v >> u;
        adj[--v].push_back(--u);
    }
    //find initial values :
    for(int i = 0 ; i < n ; i++){
        for(int j : adj[i])
            d[j]++;
    }
    for(int i = 0 ; i < n ; i++){
        if(d[i] == 0){
            sources.push_back(i);
        }
    }
    //algorithm :
    while(!sources.empty()){
        int v = sources.back();
        sorted.push_back(v);
        sources.pop_back();
        for(int i = 0 ; i < adj[v].size() ; i++){
            if(--d[adj[v][i]] == 0){
                sources.push_back(adj[v][i]);
            }
        }
    }
    for(int i : sorted){
        cout << i + 1 << ' '; 
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    solve();
    return 0;
}
