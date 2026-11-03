#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;

const int N  = 2e5 + 10;

inline int in(){
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int n = in();
    int k = in();
    pair<ll , int> r[n];
    fo(i , n){
        int x;
        cin >> x;
        r[i] = {x , i};
    }
    sort(r , r + n);
    vector<int> dp(n + 1 , 0);
    int cnt = 1;
    for(int i = 1 ; i < n ; ++i){
        if(r[i].first == r[i - 1].first){
            dp[i] = dp[i - 1];
            cnt++;
        }
        else{
            dp[i] = dp[i - 1] + cnt;
            cnt = 1;
        }
    }
    vector<int> pos(n);
    fo(i, n) {
        pos[r[i].second] = i;
    }
    fo(i , k){
        int v , u;
        cin >> v >> u;
        v--;
        u--;
        if(r[pos[v]].first > r[pos[u]].first){
            dp[pos[v]]--;
        }
        if(r[pos[v]].first < r[pos[u]].first){
            dp[pos[u]]--;
        }
    }
    vector<int> ans(n , 0);
    fo(i , n){
        ans[r[i].second] = dp[i];
    }
    for(int i : ans){
        cout << i << ' ';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //t = in();
    while(t--){
        solve();
    }
    return 0;
}