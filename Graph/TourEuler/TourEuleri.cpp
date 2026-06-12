#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int M = 1e5;
vector<int> adj[N];
vector<int> ind[N];
vector<int> ans;
int ptr[N];
bool mark[M];


void tour(int v){
    while(ptr[v] < adj[v].size()){
        int u = adj[v][ptr[v]];
        int index = ind[v][ptr[v]];
        ptr[v]++;
        if(!mark[index]){
            mark[index] = true;
            tour(u);
        }
    }
    ans.push_back(v);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n , m;
    cin >> n >> m;
    int v , u;
    for(int i = 0 ; i < m ; i++){
        cin >> v >> u;
        v--; u--;
        adj[v].push_back(u);
        adj[u].push_back(v);
        ind[v].push_back(i);
        ind[u].push_back(i);

    }
    tour(0);
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] + 1 << ' ';
    }
    cout << endl;
    return 0;
}