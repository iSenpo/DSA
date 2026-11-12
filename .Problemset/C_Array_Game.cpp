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
const ll INF = 4e18 + 100;
const int MIN = -2e9 - 100;
//always check input!!!

void solve()
{
    ll n , k;
    cin >> n >> k;
    ll a[n];
    fo(i , n) cin >> a[i];
    sort(a , a + n);
    if(k >= 3){
        cout << 0 << ln;
        return;
    }
    if(k == 1){
        ll ans = min({*min_element(a , a + n) , abs(a[1] - a[0]) , abs(a[n - 1] - a[n - 2])});
        for(ll i = 1 ; i < n - 1 ; i++){
            ans = min({ans , abs(a[i] - a[i - 1]) , abs(a[i] - a[i + 1])});
        }
        cout << ans << ln;
        return;
    }
    ll ans = *min_element(a , a + n);
    for(ll i = 0 ; i < n ; i++){
        for(ll j = i + 1 ; j < n ; j++){
            ll x = abs(a[i] - a[j]);
            ans = min(ans , x);
            ll dw = 0 , up = n - 1;
            ll best = INF;
            while(dw <= up){
                ll mid = (dw + up) / 2;
                best = min(best , abs(a[mid] - x));
                if(a[mid] > x){
                    up = mid - 1;
                }
                else{
                    dw = mid + 1;
                }
            }
            ans = min(ans , best);
        }
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
