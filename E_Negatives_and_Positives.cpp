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
    int a[n];
    int cnt = 0;
    fo(i , n){
        cin >> a[i];
        if(a[i] < 0) cnt++;
    } 
    ll ans = 0;
    if(count(a , a + n , 0) > 0 || cnt % 2 == 0){
        fo(i , n){
            ans += abs(a[i]);
        }
        cout << ans << ln;
        return;
    }
    fo(i , n) a[i] = abs(a[i]);
    sort(a , a + n);
    fo(i , n){
        ans += abs(a[i]);
    }
    ans -= (2 * abs(a[0]));
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
