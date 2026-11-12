#include <bits/stdc++.h>
using namespace std;
#define ll uint64_t
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

ll calc(ll x){
    ll r = 0;
    if((x % 2) == 0){
        r = (x / 2) * (x + 1);
    }
    else{
        r = ((x + 1) / 2) * x;
    }
    return r;
}
void solve()
{
    ll n , k;
    cin >> n >> k;
    ll ans = 0;
    if(calc(n) <= k){
        k -= (calc(n));
        ans += n;
        ll ans2 = 0;
        ll dw = 1 , up = n;
        ll j = calc(n - 1);
        while(dw <= up){
            ll m = (dw + up) / 2;
            ll c = j - calc(m);
            if(k >= c){
                ans2 = m;
                up = m - 1;
            }
            else{
                dw = m + 1;
            }
        }
        ans += (n - 1 - ans2);
        k -= (j - calc(ans2));
        if(k > 0 && ans < (2 * n) - 1){
            ans++;
        }
    }
    else{
        ll dw = 1 , up = n;
        while(dw <= up){
            ll m = (dw + up) / 2;
            if(calc(m) <= k){
                ans = max(ans , m);
                dw = m + 1;
            }
            else{
                up = m - 1;
            }
        }
        k -= calc(ans);
        if(k > 0){
            ans++;
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
