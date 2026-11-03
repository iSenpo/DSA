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
    int n , q;
    cin >> n >> q;
    int a[n];
    fo(i , n) cin >> a[i];
    vector<ll> ps(n + 1);
    ps[0] = 0;
    fo(i , n) ps[i + 1] = ps[i] + a[i];
    int mx[n];
    mx[0] = a[0];
    for(int i = 1; i < n ; i++){
        mx[i] = max(mx[i - 1] , a[i]);
    }
    while(q--){
        int k;
        cin >> k;
        int l = 0 , r = n - 1;
        int m = (l + r)/2;
        int flag = -1;
        while(l <= r){
            m = (l + r)/2;
            if(mx[m] <= k){
                l = m + 1;
                flag = m;
            }
            else{
                r = m - 1;
            }
        }
        if(flag == -1){
            cout << 0 << ' ';
            continue;
        }
        cout << ps[flag + 1] << ' ';
    }
    cout << ln;
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
