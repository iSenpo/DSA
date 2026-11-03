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
    int n;
    cin >> n;
    int l , r;
    cin >> l >> r;
    int a[n];
    fo(i , n) cin >> a[i];
    ll ans = 0;
    sort(a , a + n);
    for(int i = 0 ; i < n - 1 ; i++){
        int dw = i + 1;
        int up = n - 1;
        int lowest = -1 , highest = -1;
        while(dw <= up){
            int mid = (dw + up)/2;
            int v = a[mid] + a[i];
            if(v >= l && v <= r){
                lowest = mid;
                up = mid - 1;
            }
            else if(v > r){
                up = mid - 1;
            }
            else if(v < l){
                dw = mid + 1;
            }
        }
        dw = i + 1;
        up = n - 1;
        while(dw <= up){
            int mid = (dw + up)/2;
            int v = a[mid] + a[i];
            if(v >= l && v <= r){
                highest = mid;
                dw = mid + 1;
            }
            else if(v > r){
                up = mid - 1;
            }
            else if(v < l){
                dw = mid + 1;
            }
        }
        if(highest == -1 || lowest == -1) continue;
        ans += (highest - lowest) + 1;
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
