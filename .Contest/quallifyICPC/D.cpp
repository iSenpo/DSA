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
const int N  = 1e6 + 10;
const int INF = 2e9 + 100;
const int MIN = -2e9 - 100;
//always check input!!!


bool mark[N];
vector<int> adj[N];
vector<int> ans;

void dfs(int v){
    mark[v] = true;
    for(int i : adj[v]){
        if(!mark[i]){
            dfs(i);
        }
    }
    ans.push_back(v + 1);
}
void solve()
{
    int n;
    cin >> n;
    string s[n];
    ans.clear();
    fo(i , n) {
        cin >> s[i];
        adj[i].clear();
        mark[i] = false;
    }
    fo(i , n){
        fo(j , n){
            if(s[i][j] == '1'){
                adj[i].push_back(j);
            }
            if(s[i][j] == '?'){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    dfs(0);
    if(ans.size() != n){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        for(int i = 0 ; i < ans.size() - 1 ; i++){
            cout << ans[i + 1] << ' ' << ans[i] << ln;
        }
    }
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
