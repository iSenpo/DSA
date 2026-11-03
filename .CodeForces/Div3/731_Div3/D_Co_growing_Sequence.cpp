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
    ll a[n];
    fo(i , n) cin >> a[i];
    vector<ll> ans(n , 0);
    for(ll i = 1 ; i < n ; i++){
        ll p = a[i - 1];
        ll c = a[i];
        for(int j = 0 ; j < 31 ; j++){
            ll k = (1 << j);
            if((p & k) && (c & k)){
                p -= k;
                c -= k;
            }
            else if((p & k) && !(c & k)){
                p -= k;
                ans[i] += k;
                a[i] += k;
            }
            else if(!(p & k) && (c & k)){
                c -= k;
            }
            if(p == 0){
                break;
            }
        }
    }
    fo(i , n) cout << ans[i] << ' ';
    cout << ln;
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
