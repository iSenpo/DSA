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

ll n;
ll calc(ll k , ll value){
    ll ans = 0;
    ll base = 1;
   while(k-- && ans * value < 1e18) {
    if(1e18 / value < ans){
        break;
    }
    ans += base;
    base *= value;
   }
   return ans;
}
void solve()
{
    cin >> n;
    for(int i = 2 ; i < 60 ; i++){
        ll dw = 7 , up = 1e9;
        ll mid = (dw + up)/2;

        while(dw <= up){
            mid = (dw + up)/2;
            if(calc(i , mid) == n){
                cout << "YES\n";
                return;
            }
            else if(calc(i , mid) < n){
                dw = mid + 1;
            }
            else if(calc(i , mid) > n){
                up = mid - 1;
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
