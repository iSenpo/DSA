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
const int N  = 4e5 + 10;
const int INF = 2e9 + 100;
const int MIN = -2e9 - 100;
//always check input!!!

vector<int> adj[N];
int layer[N] , rem[N];
void solve()
{
    int n , k;
    cin >> n >> k;
    fo(i , n + 10){
        adj[i].clear();
        layer[i] = 0;
        rem[i] = 0;
    }
    fo(i , n - 1){
        int v , u;
        cin >> v >> u;
        v--;
        u--;
        adj[v].push_back(u);
        adj[u].push_back(v);
        rem[v]++;
        rem[u]++;
    }
    queue<int> q;
    fo(i , n){
        if(rem[i] == 1){
            q.push(i);
            layer[i] = 1;
        }
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i : adj[v]){
            if(rem[i] != 1){
                rem[i]--;
                if(rem[i] == 1){
                    layer[i] = layer[v] + 1;
                    q.push(i);
                }
            }
        }
    }
    int ans = 0;
    fo(i , n){
        if(layer[i] > k){
            ans++;
        }
    }
    cout << ans << ln;
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
