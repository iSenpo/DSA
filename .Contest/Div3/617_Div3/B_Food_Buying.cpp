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

ll power(int n , int t){
    ll r = 1;
    while(t-- > 0){
        r *= n;
    }
    return r;
}
void solve()
{
    int n;
    cin >> n;
    ll k = 0;
    while(power(10 , k) <= n){
        k++;
        if(power(10 , k) > n){
            k--;
            break;
        }
    }
    power(10 , k);
    ll ans = 0;
    while(power(10 , k) > 1 && n - (power(10 , k) / 10 * 9) > 0){
        ans += power(10 , k);
        n -= (power(10 , k) / 10 * 9);
        while(power(10 , k) / 10 * 9 > n){
            k--;
        }
    }
    //cerr << k << ' ' << p << ' ' << ans << ' ' << n;
    while(n - 10 >= 0){
        n -= 10;
        n ++;
        ans += 10;
    }
    ans += n;
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