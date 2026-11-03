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
    ll n , k ;
    cin >> n >> k;
    ll a[n];
    fo(i , n) cin >> a[i];
    sort(a , a + n);
    ll med = a[n / 2] , ans = 0;
    ll dw = med , up = 2e18;
    while(dw <= up){
        ll mid = (dw + up) / 2;
        bool check = 1;
        ll t = k;
        for(int i = n / 2 ; i < n ; i++){
            if(a[i] < mid){
                t -= (mid - a[i]);
            }
            if(t < 0){
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
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
