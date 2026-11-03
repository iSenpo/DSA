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
const int N  = 2e5 + 10;
const int INF = 2e9 + 100;
const int MIN = -2e9 - 100;
//always check input!!!

void solve()
{
    ll n;
    cin >> n;
    ll a[n + 1];
    vector<pll> pairs;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        if(a[i] < i){
            pairs.push_back({a[i] , i});
        }
    }
    sort(all(pairs));
    ll ans = 0;
    ll maxt = pairs.size();
    for(int i = 0 ; i < maxt ; i++){
        ll l = i + 1 , r = maxt - 1;
        ll best = maxt;
        while(l <= r){
            int m = (l + r) / 2;
            if(pairs[i].second < pairs[m].first){
                best = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        ans += maxt - best;
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
