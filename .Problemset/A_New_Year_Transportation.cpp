#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define mt(x , y , z) make_tuple(x , y , z)

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;

const int N  = 2e5 + 10;
//always check input!!!
bool mark[N];
int adj[N];

void dfs(int v){
    mark[v] = true;
    if(!mark[adj[v]] && adj[v] != 0){
        dfs(adj[v]);
    }
}
void solve()
{
    int n , k;
    cin >> n >> k;
    memset(adj , 0 , sizeof adj);
    memset(mark , false , sizeof mark);
    fo(i , n - 1){
        int x;
        cin >> x;
        adj[i + 1] = i + 1 + x; 
    }
    dfs(1);
    if(mark[k]){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
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