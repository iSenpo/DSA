#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10; //nodes : | 1 < x < 2e5 | | 2e5 < y < 4e5 | 
const int M = 6e5 + 10; //edges
int n;

vector<int> adj[N];
vector<int> ind[N];
int ptr[M];
bool mark_e[M] , mark_v[N];

string ans;
int color = 0;
const char col[2] = {'r' , 'b'};

void tour(int v , int i){
    mark_v[v] = true;
    while(ptr[v] < ind[v].size()){
        int u = adj[v][ptr[v]];
        int e = ind[v][ptr[v]];
        ptr[v]++;
        if(!mark_e[e]){
            mark_e[e] = true;
            tour(u , e);
        }
    }
    if(i != -1 && i < n){
        ans[i] = col[color];
    }
    color = 1 - color;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    cin >> n;
    int v , u;
    for(int i = 0 ; i < n ; i++){
        cin >> v >> u;
        u = u + 2e5;
        adj[v].push_back(u);
        adj[u].push_back(v);
        ind[v].push_back(i);
        ind[u].push_back(i);
        ans += "t"; //temp -> so we widen the string long enough
    }
    int boss = 4e5 + 1;
    int cnt = n;
    for(int i = 0 ; i < boss ; i++){
        if(adj[i].size() % 2 == 1){
            adj[i].push_back(boss);
            ind[i].push_back(cnt);
            adj[boss].push_back(i);
            ind[boss].push_back(cnt++);
        }
    }
    tour(boss , -1);
    for(int i = 1 ; i < N ; i++)
        if(!mark_v[i] && !adj[i].empty())
            tour(i , -1);
    cout << ans;
    return 0;
}