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
vector<int> dowr;

bool mark[N] , seen[N];
int n;

bool dfs(int v, int parent){
    mark[v] = true;
    for (int i : adj[v]){
        if(!mark[i]){
            if(dfs(i, v))
                return true;
        }
        else if(i != parent)
            return true;
    }
    return false;
}
void dfs2(int v){
    seen[v] = true;
    for(int i : adj[v]){
        if(!seen[i]){
            dfs2(i);
        }
    }
}
bool isCycle(int i){
    memset(mark , false , sizeof mark);
    return dfs(i, -1);
}

void solve()
{
    cin >> n;
    fo(i, n) adj[i].clear();
    dowr.clear();
    memset(seen, false, sizeof(seen));
    memset(mark, false, sizeof(mark));
    int a[n];
    fo(i , n){
        cin >> a[i];
        a[i]--;
        if(i == a[i]){
            continue;
        }
        adj[a[i]].push_back(i);
        adj[i].push_back(a[i]);
    }
    fo(i , n){
        if(!seen[i]){
            if(isCycle(i)){
                dowr.pb(i);
            }
            dfs2(i);
        }
    }
    memset(seen , false , sizeof(seen));
    int root;
    if(!dowr.empty()){
        root = dowr[0];
    }
    else{
        root = 0;
    } 
    dfs2(root);
    int ans = 0;
    fo(i , n){
        if(!seen[i]){
            ans++;
            a[i] = root;
            dfs2(i);
        }
    }
    cout << ans << ln;
    fo(i , n){
        cout << a[i] + 1 << ' ';
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