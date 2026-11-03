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
    int a[n];
    fo(i , n) cin >> a[i];

    vector<int> b(m);
    fo(i , m){
        int u;
        cin >> u;
        u--;
        b[i] = u;
    }
    sort(rall(b));

    vector<ll> ps(n + 1 , 0);
    for(int i = n - 1 ; i >= 0 ; i--){
        ps[i] = ps[i + 1] + a[i];
    }

    ll sum = ps[b[0] + 1];
    ll ss = 0;
    for(int i = 0; i <= b[m - 1] ; i++){
        ss += a[i];
    }
    sum += abs(ss);
    int x = 0;
    for(int i = 0 ; i < m - 1 ; i++){
        int r = b[i] , l = b[i + 1] + 1;
        ll cur = ps[l] - ps[r + 1];
        if(x == 1){
            cur = (-cur);
        }
        if(cur > 0){
            sum += cur;
        }
        else{
            sum += (-cur);
            x = 1 - x;
        }
    }
    cout << sum << ln;
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
