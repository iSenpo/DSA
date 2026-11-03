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
    ll n , t;
    cin >> n >> t;
    ll a[n];
    fo(i , n) cin >> a[i];
    vector<ll> pref(n + 1 , 0);

    fo(i , n){
        pref[i + 1] = pref[i] + a[i];    
    }
    ll ans = 0;
    for(ll i = 1 ; i <= n ; i++){
        int l = i , r = n;
        while(l <= r){
            int m = (l + r) / 2;
            if(pref[m] - pref[i - 1] > t){
                r = m - 1;
            }
            else{
                ans = max(m - i + 1, ans);
                l = m + 1;
            }
        }
    }
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
