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

const int N  = 2e6 + 10;
//always check input!!!
vector<int> adj[N];
int d[N];
vector<int> sorted;
set<int> sources;
int SinkCnt = 0;
void solve()
{
    int n , m;
    cin >> n >> m;
    memset(d , 0 , sizeof d);
    for(int i = 0 ; i < m ; i ++){
        int v , u;
        cin >> v >> u;
        adj[--v].push_back(--u);
    }
    for(int i = 0 ; i < n ; i++){
        if(adj[i].size() == 0){
            SinkCnt++;
        }
        for(int j : adj[i]){
            d[j]++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(d[i] == 0){
            sources.insert(i);
        }
    }
    while(!sources.empty()){
        int v = *sources.begin();
        sources.erase(sources.begin());
        sorted.push_back(v);
        for(int i : adj[v]){
            if(--d[i] == 0){
                sources.insert(i);
            }
        }
    }
    if(sorted.size() < n){
        cout << "Sandro fails.\n";
        return;
    }
    for(int i : sorted){
        cout << i + 1 << ' ';
    }
    cout << ln;
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