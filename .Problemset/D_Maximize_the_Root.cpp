#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define pll pair<ll , ll>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define	set_dec(x) cout << fixed << setprecision(x);
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;
const int N  = 2e5 + 200;
const int INF = 2e9 + 100;
const int MIN = -2e9 - 100;
//always check input!!!

int a[N];
vector<int> adj[N];
int dp[N];

void dfs(int v){
    if(!adj[v].size()){
        dp[v] = a[v];
        return;
    }
    int Max = INF;
    for(int i : adj[v]){
        dfs(i);
        Max = min(Max , dp[i]);
    }
    if(Max < a[v]){
        dp[v] = Max; 
    }
    else{
        dp[v] = (Max + a[v])/2;
    }
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        adj[i].clear();
    }
    for(int i = 2 ; i <= n ; i++){
        int v;
        cin >> v;
        adj[v].push_back(i);
    }
    int Max = INF;
    for(int i : adj[1]){
        dfs(i);
        Max = min(Max , dp[i]);
    }
    cout << a[1] + Max << ln;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
