#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define pll pair<ll , ll>
#define ln '\n'

const int N = 503;
const int INF = 1e9;

ll f[N][N][N];
ll adj[N][N];
ll worst[N];
int n , m;

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
    ll v , u , w;
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
        for(int j = 1 ; j <= n ; ++j){
            if(i == j) continue;
            worst[i] = max(worst[i] , f[n][i][j]);
        }
    }
    pll ans = {INF , 0};
    for(int i = 1 ; i <= n ; i++){
        if(ans.first > worst[i]){
            ans.first = worst[i];
            ans.second = i;
        }
    }
    cout << ans.second << ln;
    cerr << ans.first << ln;
    return 0;
}
//check long long memory limit
//check int overflow