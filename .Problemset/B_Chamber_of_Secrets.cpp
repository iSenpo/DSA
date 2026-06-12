#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

const int N  = 1e3 + 10;
vector<int> adj[N + N];
int h[N + N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n , m;
    cin >> n >> m;
    char a;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a;
            if(a == '#'){
                adj[i].push_back(n + j);
                adj[n + j].push_back(i);
            }
        }
    }
    memset(h , 63 , sizeof h);
    queue<int> q;
    q.push(0);
    h[0] = 0;
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i : adj[v]){
            if(h[v] + 1 < h[i]){
                h[i] = h[v] + 1;
                q.push(i);
            }
        }
    }
    if(h[n-1] > N * N){
        cout << -1 ;
    }
    else{
        cout << h[n-1] ;
    }
    return 0;
}