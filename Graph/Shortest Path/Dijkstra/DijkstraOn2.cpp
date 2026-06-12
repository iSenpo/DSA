#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()

const int N = 1e3 + 10;
const int INF = 1e9 + 10;

int adj[N][N];
int d[N];
int f[N];

void solve()
{
    int n , m , s;
    cin >> n >> m >> s;
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            if(i != j){
                adj[i][j] = INF;
            }
            else{
                adj[i][j] = 0;
            }
        }
    }
    for(int i = 0 ; i < m ; ++i){
        int v , u , w;
        cin >> v >> u >> w;
        //min for multy roads
        adj[v][u] = min(adj[v][u] , w);
        adj[u][v] = min(adj[u][v] , w);
    }
    for(int i = 0 ; i < N ; ++i){
        d[i] = INF;
        f[i] = INF;
    }
    f[s] = 0;
    for(int i = 1 ; i <= n ; ++i){
        int v = -1;
        int h = INF;
        for(int j = 1 ; j <= n ; ++j){
            if(d[j] == INF && h > f[j]){
                h = f[j];
                v = j;
            }
        }
        d[v] = h;
        for(int j = 1; j <= n ; ++j){
            if(d[j] == INF){
                f[j] = min(f[j] , d[v] + adj[v][j]);
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        cout << i << " : " << d[i] << '\n';
    }

}
/*
    4 4 1
    1 2 5
    1 3 1
    3 4 1
    4 2 1
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow