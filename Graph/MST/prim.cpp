#include <bits/stdc++.h>
using namespace std;
typedef pair<int , int> pii;

const int N = 1e5;

int n , m;
vector<pii> adj[N];
bool seen[N];
int min_edge[N];

int prim1(int v){
    memset(seen, 0, sizeof seen);
    memset(min_edge , 63 , sizeof min_edge);
    seen[v] = true;
    int MST = 0;
    for(pii u : adj[v])
        min_edge[u.first] = min(min_edge[u.first] , u.second);
    
    for(int i = 0 ; i < n - 1 ; i++){
        int u = -1;
        for(int j = 1 ; j <= n ; j++){
            if(!seen[j] && (u == -1 || min_edge[j] < min_edge[u])){
                u = j;
            }
        }
        seen[u] = true;
        MST += min_edge[u];
        for(pii z : adj[u]){
            if(!seen[z.first]){
                min_edge[z.first] = min(min_edge[z.first] , z.second);
            }
        }
    }
    return MST;
}
int prim2(int v){
    memset(seen, 0, sizeof seen);
    memset(min_edge , 63 , sizeof min_edge);
    set<pii> st;
    int MST = 0;
    min_edge[v] = 0;
    st.insert({0 , v});
    while(!st.empty()){
        int u = (*st.begin()).second;
        st.erase(st.begin());
        seen[u] = true;
        MST += min_edge[u];
        for(auto &[z , w] : adj[u]){
            if(!seen[z] && w < min_edge[z]){
                st.erase({min_edge[z] , z});
                min_edge[z] = w;
                st.insert({min_edge[z] , z});
            }
        }
    }
    return MST;
}
void input(){
    /*
    5 8
    1 2 1
    1 3 5
    1 5 6
    2 4 2
    2 5 10
    4 5 2
    4 3 3
    3 5 8
    */
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    cin >> n >> m;
    int v , u , w;
    for(int i = 0 ; i < m ; i++){
        cin >> v >> u >> w;
        adj[v].push_back({u , w});
        adj[u].push_back({v , w});
    }
    cout << prim1(2) << "  " << prim2(4);
    return 0;
}