#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'

const int N = 1e2 + 10;
const int INF = 1e9;

int f[N][N][N];
int adj[N][N];
int n , m;
/*
INPUT :
4 5 
1 2 -1
2 3 3
3 1 -1
3 4 2
4 1 1

OUTPUT :
1 : 0 -1 2 4 
2 : 2 0 3 5 
3 : -1 -2 0 2 
4 : 1 0 3 0
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    cin >> n >> m;
    for(int i = 0 ; i <= n ; ++i){
        for(int j = 0 ; j <= n ; ++j){
            if(i == j){
                adj[i][j] = 0;
            }
            else{
                adj[i][j] = INF;
            }
        }
    }
    int v , u , w;
    for(int i = 0 ; i < m ; ++i){
        cin >> v >> u >> w;
        adj[v][u] = min(adj[v][u] , w);
    }
    for(int i = 0 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            f[0][i][j] = adj[i][j];
        }
    }
    for(int k = 1 ; k <= n ; ++k){
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= n ; ++j){
                f[k][i][j] = min(f[k - 1][i][j] , f[k - 1][i][k] + f[k - 1][k][j]);
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        cout << i << " : "; 
        for(int j = 1 ; j <= n ; ++j){
            cout << f[n][i][j] << ' ';
        }
        cout << ln;
    }
    return 0;
}
//check long long memory limit
//check int overflow