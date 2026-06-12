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

void solve()
{
    int n;
    cin >> n;
    int a[n];
    map<int , int> cnt;
    fo(i , n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int Min = N;
    fo(i , n){
        Min = min(Min , cnt[a[i]]);
    }
    int k = 0;
    vector<pii> ans;
    fo(i , n){
        if(cnt[a[i]] == Min){
            ans.push_back({a[i] , i + 1});
        }
    }
    sort(all(ans));
    if(cnt[ans[0].first] > 1){
        cout << -1 << ln;
    }
    else{
        cout << ans[0].second << ln;
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