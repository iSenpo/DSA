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
    ll n , c , d;
    cin >> n >> c >> d;
    vector<ll> a(n);
    fo(i , n) cin >> a[i];
    sort(rall(a));
    if(a[0] >= c){
        cout << "Infinity\n";
        return;
    }
    if((a[0] * d) < c){
        cout << "Impossible\n";
        return;
    }
    ll dw = 0 , up = INF;
    ll ans = -1;
    while(dw <= up){
        ll m = (dw + up) / 2;
        if(m > d){
            ll sum = 0;
            for(int i = 0 ; i < min(n , d) ; i++){
                sum += a[i];
            }
            if(sum >= c){
                ans = max(ans , m);
                dw = m + 1;
            }
            else{
                up = m - 1;
            }
            continue;
        }
        ll sum = 0;
        if(m == 0){
            sum = (a[0] * d);
            if(sum >= c){
                ans = max(ans , m);
                dw = m + 1;
            }
            else{
                up = m - 1;
            }
            continue;
        }
        if(m == d){
            for(int i = 0 ; i < min(d , n) ; i++){
                sum += a[i];
            }
            if(sum >= c){
                ans = max(ans , m);
                dw = m + 1;
            }
            else{
                up = m - 1;
            }
            continue;
        }
        ll t = d / (m + 1);
        ll r = d - (t * (m + 1));
        for(int i = 0 ; i < min(n , (m + 1)) ; i++){
            sum += (a[i] * t);
        }
        for(int i = 0 ; i < min(n , r) ; i++){
            sum += a[i];
        }
        if(sum >= c){
            ans = max(ans , m);
            dw = m + 1;
        }
        else{
            up = m - 1;
        }
    }
    if(ans == INF){
        cout << "Infinity\n";
        return;
    }
    if(ans == -1){
        cout << "Impossible\n";
        return;
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
