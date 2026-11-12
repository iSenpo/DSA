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
const ll INF = 2e18 + 100;
const int MIN = -2e9 - 100;
//always check input!!!

void solve()
{
    ll n , m;
    cin >> n >> m;
    ll a[n];
    fo(i , n) cin >> a[i];
    ll b[m];
    fo(i , m) cin >> b[i];
    ll ans = INF;
    ll best[n];
    for(ll i = 0; i < n ; i++){
        ll less = INF;
        ll dw = 0 , up = m - 1;
        while(dw <= up){
            ll mid = (dw + up) / 2;
            if(abs(a[i] - b[mid]) < abs(a[i] - less)){
                less = b[mid];
            }
            if(a[i] == b[mid]){
                less = b[mid];
                break;
            }
            if(b[mid] < a[i]){
                dw = mid + 1;
            }
            else{
                up = mid - 1;
            }
        }
        best[i] = less;
    }
    ll dw = 0 , up = INF;
    while(dw <= up){
        ll mid = (dw + up) / 2;
        bool check = 1;
        for(ll i = 0 ; i < n ; i++){
            if(a[i] >= best[i] - mid && a[i] <= best[i] + mid){
                continue;
            }
            else{
                check = 0;
                break;
            }
        }
        if(check){
            ans = min(ans , mid);
            up = mid - 1;
        }
        else{
            dw = mid + 1;
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
