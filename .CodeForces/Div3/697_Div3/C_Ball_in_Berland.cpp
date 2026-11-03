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
    ll n , m , k;
    cin >> n >> m >> k;
    ll a[k] , b[k];
    vector<ll> cnt1(n + 10 , 0) , cnt2(m + 10 , 0);
    map<pii , ll> cnt; 
    fo(i , k)
        cin >> a[i];
    fo(i , k)
        cin >> b[i];
    ll ans = 0;
    for(ll i = 0 ; i < k ; i++){
        ans += max(0LL , ((0LL + i - cnt1[a[i]] - cnt2[b[i]]) + cnt[{a[i] , b[i]}]));
        cnt1[a[i]]++;
        cnt2[b[i]]++;
        cnt[{a[i] , b[i]}]++;
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
