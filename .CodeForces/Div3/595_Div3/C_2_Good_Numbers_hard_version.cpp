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

ll power(ll a , ll p){
    ll r = 1;
    while(p--){
        r *= a;
    }
    return r;
}
void solve()
{
    ll n;
    cin >> n;
    vector<bool> mark(40 , false);
    ll ans = 0;
    for(int i = 39 ; i >= 0 ; i--){
        if(n - power(3 , i) >= 0){
            ans += power(3 , i);
            n -= power(3 , i);
            mark[i] = true;
        }
    }
    if(n > 0){
        for(int i = 0 ; i <= 39 ; i++){
            if(mark[i]){
                ans -= power(3 , i);
            }
            else{
                ans += power(3 , i);
                break;
            }
        }
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
