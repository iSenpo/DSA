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
const int INF  = 2e8;
//always check input!!!

vector<int> adj[N];
vector<int> d;

void solve()
{   
    int n , m;
    cin >> n >> m;
    d = vector<int>(n + 1, INF);
    for(int i = 0 ; i <= n + 10 ; i++){
        adj[i].clear();
    }
    fo(i , m){
        int v , u;
        cin >> v >> u;
        v--;
        u--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    queue<int> q;
    q.push(0);
    d[0] = 0;
    vector<int> odd , even;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : adj[v]){
            if(d[u] == INF){
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    fo(i , n){
        if(d[i]%2 == 0){
            even.push_back(i + 1);
        }
        else{
            odd.push_back(i + 1);
        }
    }
    if(sz(even) < sz(odd)){
        cout << sz(even) << ln;
        for(int i : even){
            cout << i << ' ';
        }
        cout << ln;
    }
    else{
        cout << sz(odd) << ln;
        for(int i : odd){
            cout << i << ' ';
        }
        cout << ln;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow