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
    long double  d , h;
    cin >> d >> h;
    long double a[n];
    fo(i , n) cin >> a[i];
    sort(a , a + n);
    fo(i , 5){
        
    }
    long double ans = ((d * h) / 2);
    fo(i , n - 1){
        if(a[i] + h > a[i + 1]){
            long double Hp = h - (a[i + 1] - a[i]);
            long double Bp = (Hp * d) / (h);
            ans -= ((Hp * Bp) / 2);
        }
        ans += (long double)(d * h) / 2;
    }
    set_dec(7);
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
