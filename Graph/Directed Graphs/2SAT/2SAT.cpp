#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'

const int N = 1e5 + 10;
vector<int> adj[2 * N][2];
vector<int> topol_sort;
bool mark[2 * N];
int n , m , c = 0;
int color[2 * N];
//  v --> 2v      ||  0 --> 0
// ~v --> 2v + 1  || -0 --> 1
//                ||  1 --> 2
//                || -1 --> 3

void add_clause(int v , int u){
    if(v < 0)
        v = (-2 * v) - 1;
    else
        v = (2 * v) - 2;
    if(u < 0)
        u = (-2 * u) - 1;
    else
        u = (2 * u) - 2;

    int notv = (v ^ 1);  // == 1 - v
    int notu = (u ^ 1);  // == 1 - u
    // 0 = to(Out)    ,    1 = from(In)
    adj[notv][0].push_back(u);     // ~v ==>  u 
    adj[u][1].push_back(notv);     //  u ==> ~v
    adj[notu][0].push_back(v);     // ~u ==>  v
    adj[v][1].push_back(notu);     //  v ==> ~u
}
// dfs for topological sort
void dfs_t(int v){
    mark[v] = 1;
    for(int i : adj[v][0]){
        if(!mark[i]){
            dfs_t(i);
        }
    }
    topol_sort.push_back(v);
}
// dfs to find scc
void dfs_c(int v){
    mark[v] = 1;
    for(int i : adj[v][1]){
        if(!mark[i]){
            dfs_c(i);
        }
    }
    color[v] = c;
} 
void find_scc(){
    //find topological sort : 
    for(int i = 0 ; i < 2 * n ; i++){
        if(!mark[i]){
            dfs_t(i);
        }
    }
    reverse(topol_sort.begin() , topol_sort.end());

    //scc :
    memset(mark , false , sizeof mark);
    for(int i : topol_sort){
        if(!mark[i]){
            dfs_c(i);
            c++;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int v , u;
        cin >> v >> u;
        add_clause(v , u);
    }
    // find topological sort than scc
    find_scc();
    // find answer and than output the answer:
    for(int i = 0 ; i < n ; i ++){
        mark[i] = color[(2 * i)] > color[(2 * i) ^ 1];
        if(color[(2 * i)] == color[(2 * i) ^ 1]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i = 0 ; i < n ; i++){
        cout << mark[i] << ln;
    }
    return 0;
}
/*
3 3
1 -3
-1 -2
2 3
*/
