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
    ll n , m;
    cin >> n >> m;
    ll a[n];
    fo(i , n) cin >> a[i]; 
    vector<ll> v1 , v2;
    fo(i , n){
        int b;
        cin >> b;
        if(b == 1){
            v1.pb(a[i]);
        }
        else{
            v2.pb(a[i]);
        }
    }
    sort(rall(v1));
    sort(rall(v2));
    vector<ll> ps1(v1.size() + 1 , 0) , ps2(v2.size() + 1 , 0);
    for(int i = 0 ; i < v1.size() ; i++){
        ps1[i + 1] = ps1[i] + v1[i];
    }
    for(int i = 0 ; i < v2.size() ; i++){
        ps2[i + 1] = ps2[i] + v2[i];
    }
    ll ans = INF;
    for(ll i = 0 ; i <= v1.size() ; i++){
        if(ps1[i] >= m){
            ans = min(ans , i);
        }
        int dw = 0 , up = v2.size();
        while(dw <= up){
            int i2 = (dw + up)/2;
            if(ps2[i2] + ps1[i] >= m){
                ans = min(ans , i + ((i2) * 2));
                up = i2 - 1;
            }
            else{
                dw = i2 + 1;
            }
        }
    }
    if(ans == INF) cout << -1 << ln;
    else{
        cout << ans << ln;
    }
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
