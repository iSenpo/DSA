#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pii> adj[N];
bool mark[N];
int d[N];
int par[N];
int n , m , source;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    memset(d , INF , sizeof d);
    memset(par , -1 , sizeof par);
    cin >> n >> m >> source;
    int v , u , w;
    for(int i = 0 ; i < m ; ++i){
        cin >> v >> u >> w;
        adj[v].push_back({u , w});
        //if undirected :
        adj[u].push_back({v , w});
    }
    d[source] = 0;
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        mark[v] = false;
        /*
        //if you are searching for 1 vertex's best path :
        if(d[v] > d[n - 1]){
            continue;
        }
        */
        for(int i = 0 ; i < adj[v].size() ; ++i){
            int u = adj[v][i].first;
            int w = adj[v][i].second;
            if(d[v] + w < d[u]){
                d[u] = d[v] + w;
                //if you need path:
                par[u] = v;
                if(!mark[u]){
                    mark[u] = true;
                    q.push(u);
                }
            }
        }
    }
    for(int i = 0 ; i <= n ; i++){
        cout << i << " : " << d[i] << ln;
    }
    return 0;
}
//check long long memory limit
//check int overflow