#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

const int N  = 1e5 + 500;

vector<pair<int , int>> adj[N];
int n , m;
int h[N];

void input(){
    cin >> n >> m;
    int v , u , x;
    for(int i = 0 ; i < m ; i++){
        cin >> v >> u >> x;
        v--;
        u--;
        adj[v].push_back({u , x});
        adj[u].push_back({v , x});
    }
    /*
    input:
    6 7
    1 2 0
    1 3 0
    2 3 0
    3 4 1
    4 5 0
    4 6 0
    5 6 0
     
    output:
    0 0 0 1 1 1
     */
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    input();
    memset(h , 63 , sizeof h);
    deque<int> q;
    q.push_back(0);
    h[0] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop_front();
        for(pair<int , int> i : adj[v]){
            int u = i.first;
            int w = i.second;
            if(h[v] + w < h[u]){
                h[u] = h[v] + w;
                if(w == 1){
                    q.push_back(u);
                }
                else{
                    q.push_front(u);
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << h[i] << " ";
    }
    return 0;
}