#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
typedef long long ll;
const int N = 1e5 + 5;
const int INF = 2e9;
bool check[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n , m , k;
    cin >> n >> m >> k;
    if(n == k || k == 0){
        cout << -1;
        return 0;
    }
    vector<pair<int , int>> adj[n];
    int u , v , l;
    for(int i = 0 ; i < m ; i++){
        cin >> u >> v >> l;
        u--;
        v--;
        adj[u].push_back({v , l});
        adj[v].push_back({u , l});
    }
    int temp;
    for(int i = 0 ; i < k ; i++){
        cin >> temp;
        temp--;
        check[temp] = true; 
    }
    int Min = INF;
    for(int i = 0 ; i < n ; i++){
        if(check[i]){
            for(int j = 0 ; j < adj[i].size() ; j++){
                if(!check[adj[i][j].first]){
                    Min = min(Min , adj[i][j].second);
                }
            }
        }
    }
    if(Min == INF){
        cout << -1;
    }
    else{
        cout << Min;
    }
    return 0;
}