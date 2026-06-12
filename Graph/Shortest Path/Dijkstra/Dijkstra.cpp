#include <bits/stdc++.h>
using namespace std;
typedef pair<int , int> pii;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

set<pii> st;
vector<pii> adj[N];
int d[N];

int main()
{
    int n , m , source;
    cin >> n >> m >> source;

    for(int i = 0 ; i < m ; ++i){
        int v , u , w;
        cin >> v >> u >> w;
        adj[v].push_back({u , w});
        adj[u].push_back({v , w});
    }

    fill(d + 1 , d + n + 1 , INF);
    st.insert({0 , source});

    while(!st.empty()){
        int v = st.begin()->second;
        int w = st.begin()->first;
        st.erase(st.begin());
        if(d[v] != INF){
            continue;
        }
        d[v] = w;
        for(int i = 0 ; i < adj[v].size() ; i++){
            if(d[adj[v][i].first] == INF){
                st.insert({d[v] + adj[v][i].second , adj[v][i].first});
            }
        }
    }
    for(int i = 0 ; i <= n ; i++){
        cout << i <<" : " << d[i] << '\n';
    }
    return 0;
}