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

const int N  = 1e6 + 500;
//always check input!!!

bool mark[N];
vector<int> adj[N];

void solve()
{
    int n , k;
    cin >> n >> k;
    fo(i , n - 1){
        int v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    int a[k];
    map<int , bool> g;
    deque<int> q;
    fo(i , k){
        cin >> a[i];
        g[a[i]] = true;
        q.push_front(a[i]);
        mark[a[i]] = true;
    }
    int ans = 0;
    int cnt = 1;
    while(!q.empty()){
       int x = q.size();
        for(int i = 0 ; i < x ; i++){
            int v = q.front();
            q.pop_front();
            for(int j : adj[v]){
                if(!mark[j]){
                    q.push_back(j);
                    mark[j] = true;
                }
                else{
                    cnt++;
                }
            }
        }
        ans++;
        if(cnt == k){
            break;
        }
    }
    if(ans%2 == 0){
        cout << ans/2 << ln;
    }
    else{
        cout << (ans + 1)/2 << ln;
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