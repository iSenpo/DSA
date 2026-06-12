#include <bits/stdc++.h>
using namespace std;

const int N  = 1e5 + 500;

pair<int , pair<int , int>> edge[N];
int par[N] , Rank[N];
vector<pair<int , int>> e;

int find(int v){
    if(par[v] == -1)
        return v;
    return find(par[v]);
}

bool merge(int v , int u){
    if((v = find(v)) == (u = find(u)))
        return false;
    if(Rank[u] > Rank[v])
        swap(v , u);
    par[u] = v;
    Rank[v] = max(Rank[v] , Rank[u]  + 1);
    return true;
}

int main(){
    int n , m;
    cin >> n >> m;
    memset(par , -1 , sizeof par);
    for(int i = 0 ; i < m ; i++){
        int v , u , w;
        cin >> v >> u >> w;
        edge[i] = {w , {v , u}};
    }
    sort(edge , edge + m);
    for(int i = 0 ; i < m ; i++){
        int v = edge[i].second.first;
        int u = edge[i].second.second;
        if(merge(v , u)){
            e.push_back({v , u});
        }
    }
    for(int i = 0 ; i < e.size() ; i++){
        cout << e[i].first << ' ' << e[i].second << endl;
    }
    return 0;
}