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

ll power(int a , int p){
    ll r = 1;
    while(p--){
        r *= a;
    }
    return r;
}
void solve()
{
    ll a , b;
    cin >> a >> b;
    int cnt = 0;
    if(a == b){
        while(a > 0){
            cnt++;
            a /= 10;
        }
        cout << cnt * 2 << ln;
        return;
    }
    int d = abs(a - b);
    ll diff = d;
    int td = 0;
    while(d > 0){
        td++;
        d /= 10;
    }
    int n = td;
    int ans = 0;
    int ta = a , tb = b ;
    while(td--){
        ta /= 10;
        tb /= 10;
    }
    while(ta > 0){
        if(ta%10 == tb%10){
            ans += 2;
        }
        else{
            ans++;
        }
        ta /= 10;
        tb /= 10;
    }
    ll zero = 2 * power(10 , n);
    if(diff < zero){
        ans += 1;
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
