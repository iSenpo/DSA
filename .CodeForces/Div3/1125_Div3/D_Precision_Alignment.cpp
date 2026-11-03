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
const ll MIN = -4e18 - 100;
//always check input!!!

void solve()
{
    ll n , k;
    cin >> n >> k;
    ll a[n] , b[n] , c[n];
    fo(i , n) cin >> a[i] >> b[i] >> c[i];

    ll dw = -4e9 - 100 , up = 4e18 + 100;
    ll ans = MIN;
    while(dw <= up){
        ll mid = (dw + up) / 2;
        ll k2 = k;
        bool check = true;
        fo(i , n){
            ll sum = a[i] + b[i] + c[i];
            if(sum >= mid) continue;
            if(a[i] == b[i] && a[i] == c[i]){
                check = false;
                break;
            }
            if(a[i] > b[i] || a[i] > c[i] || b[i] > c[i]){
                k2 -= (mid - sum);
            }
            else{
                ll Min = min(b[i] - a[i] + 1 , c[i] - b[i] + 1);
                k2 -= ((2 * Min) + (mid - sum));
            }
            if(k2 < 0){
                check = false;
                break;
            }
        }
        if(check){
            ans = max(ans , mid);
            dw = mid + 1;
        }
        else{
            up = mid - 1;
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
