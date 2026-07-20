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
const ll MIN = -2e17 - 100;
//always check input!!!

void solve()
{
    ll n , m;
    cin >> n >> m;
    ll a[n] , b[m + 1];
    fo(i , n) cin >> a[i];
    fo(i , m) cin >> b[i + 1];
    b[0] = 0;
    sort(b + 1 , b + m + 1);
    ll ans = accumulate(a , a + n , 0LL);
    vector<ll> MaxP(m + 1 , MIN) , MaxN(m + 1 , MIN) , ps(n + 1 , 0);
    fo(i , n){
        ps[i + 1] = ps[i] + a[i];
    }
    MaxP[0] = 0;
    MaxN[0] = 0;
    for(int i = 1 ; i <= m ; i++){
        MaxP[i] = ps[b[i]] - ps[b[i - 1]] + max(MaxP[i - 1] , MaxN[i - 1]);
        MaxN[i] = -(ps[b[i]] - ps[b[i - 1]]) - min(MaxP[i - 1] , MaxN[i - 1]);
        ans = max(ans , max(MaxP[i] , MaxN[i]) + ps[n] - ps[b[i]]); 
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
