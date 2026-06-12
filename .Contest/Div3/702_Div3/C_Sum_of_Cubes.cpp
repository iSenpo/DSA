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
    for(ll i = 1 ; (ll)(i * (1LL) * i * (1LL) * i) < n ; i++){
        ll dw = 1 , up = 1e4;
        ll a = (ll)(i * (1LL) * i * (1LL) * i);
        while(dw <= up){
            ll mid = (dw + up)/2;
            ll b = (ll)(mid * (1LL) * mid * mid);
            if(a + b == n){
                cout << "YES\n";
                return;
            }
            if(a + b > n){
                up = mid - 1;
            }
            if(a + b < n){
                dw = mid + 1;
            }
        }
    }
    cout << "NO\n";
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
