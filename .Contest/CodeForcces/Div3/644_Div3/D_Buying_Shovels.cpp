#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define mt(x , y , z) make_tuple(x , y , z)

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;

const int N  = 2e5 + 10;
//always check input!!!

void solve()
{
    ll n , k;
    cin >> n >> k;
    ll d = 1;
    if(k >= n){
        cout << 1 << ln;
        return;
    }
    ll ans = n;
    for(int i = 2 ; i <= min<ll>(sqrt<ll>(n) , k) ; i++){
        if(n%i == 0){
            d = max<ll>(d , i);
            if(n/i <= k){
                d = max<ll>(d , n/i);
            }
        }
    }
    //cerr << d << ln;
    ans = (n / d);
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow