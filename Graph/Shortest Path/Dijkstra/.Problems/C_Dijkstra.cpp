#include <bits/stdc++.h>
using namespace std;
typedef pair<int , int> pii;

const int N = 1e5 + 1;
const int INF = 1e8;

set<pair<int , pair <int , int>>> st;
vector<vector<pii>> adj;
int d[N];
int par[N];

int main(){
    int n , m , source;
    cin >> n >> m;
    adj.resize(n + 5);
    source = 1;
    int v , u , w;
    for(int i = 0 ; i < m ; ++i){
        cin >> v >> u >> w;
        adj[v].push_back({u , w});
        adj[u].push_back({v , w});
    }

    fill(d + 1 , d + n + 1 , INF);
    st.insert({0 , {-1 , source}});

    while(!st.empty()){
        int w = st.begin()->first;
        int v = (st.begin()->second).second;
        int p = (st.begin()->second).first;
        st.erase(st.begin());
        if(d[v] != INF){
            continue;
        }
        d[v] = w;
        par[v] = p;
        for(int i = 0 ; i < adj[v].size() ; i++){
            if(d[adj[v][i].first] == INF){
                st.insert({d[v] + adj[v][i].second ,{v , adj[v][i].first}});
            }
        }
    }
    if(d[n] == INF){
        cout << -1 << '\n';
        return 0;
    }
    int k = n;
    vector<int> path;
    while(k != source){
        path.push_back(k);
        k = par[k];
    }
    path.push_back(source);
    reverse(path.begin() , path.end());
    for(int i = 0 ; i < path.size() ; ++i){
        cout << path[i] << ' ';
    }
    cout << '\n';
    return 0;
}