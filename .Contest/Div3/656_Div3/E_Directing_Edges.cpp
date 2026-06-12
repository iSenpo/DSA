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
vector<int> adj[N];
vector<bool> mark;

void solve()
{
    int n , m;
    cin >> n >> m;
    vector<pii> idk , ans;
    vector<int> source , sorted , pos(n) , d(n , 0);
    fo(i , n + 10){
        adj[i].clear();
    }
    fo(i , m){
        int a , v , u;
        cin >> a >> v >> u;
        v--;
        u--;
        if(a == 1){
            adj[v].push_back(u);
            ans.push_back({v , u});
        }
        else{
            idk.push_back({v , u});
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j : adj[i]){
            d[j]++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(d[i] == 0){
            source.push_back(i);
        }
    }
    while(!source.empty()){
        int v = source.back();
        source.pop_back();
        sorted.push_back(v);
        for(int i : adj[v]){
            d[i]--;
            if(d[i] == 0){
                source.push_back(i);
            }
        }
    }
    if(sorted.size() < n){
        cout << "NO\n";
        return;
    }
    for(int i = 0 ; i < n ; i++){
        pos[sorted[i]] = i;
    }
    for(pii i : idk){
        int v = i.first;
        int u = i.second;
        if(pos[v] < pos[u]){
            ans.push_back({v , u});
        }
        else{
            ans.push_back({u , v});
        }
    }
    cout << "YES\n";
    for(pii i : ans){
        cout << i.first + 1 << ' ' << i.second + 1 << ln;
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