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
int cnt[N];
void dfs(int v , int par = -1){
    for(int i : adj[v]){
        if(i != par){
            dfs(i , v);
            cnt[v] += cnt[i];
        }
    }
}
struct yal{
    ll gain;
    ll w;
    int v , u;
};
struct cmp{
    bool operator()(yal const &a ,yal const &b) const{
        if(a.gain > b.gain){
            return true;
        }
        return false;
    }
};
void solve()
{
    ll n , S;
    cin >> n >> S;
    vector<pair<int , pii>> edge;
    fo(i , n){
        adj[i].clear();
        cnt[i] = 0;
    }
    fo(i , n - 1){
        int v , u , w;
        cin >> v >> u >> w;
        v--;
        u--;
        adj[v].pb(u);
        adj[u].pb(v);
        edge.push_back({w , {v , u}});
    }
    fo(i , n){
        if(adj[i].size() == 1){
            cnt[i] = 1;
        }
    }
    dfs(0);
    ll sum = 0;
    set<yal , cmp> st;
    for(auto i : edge){
        int a = i.second.first;
        int b = i.second.second;
        ll w = i.first;
        ll gain = w * (1LL) * min(cnt[a] , cnt[b]);
        sum += gain;
        st.insert({gain , w , a , b});
    }
    int ans = 0;
    while(sum > S){
        auto v = *st.begin();
        st.erase(st.begin());
        int a = v.v;
        int b = v.u;
        ll w = v.w;
        int leaves = min(cnt[a] , cnt[b]);
        ll old_contribution = w * leaves;
        ll new_w = w / 2;
        ll new_contribution = new_w * leaves;
        sum -= (old_contribution - new_contribution);
        ans++;
        w = new_w;
        ll next_gain = (w - w/2) * leaves;
        st.insert({next_gain, w, a, b});
    }
    cout << ans << ln;
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