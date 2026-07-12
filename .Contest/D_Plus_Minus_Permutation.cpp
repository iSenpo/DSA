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
ll gcd(ll a , ll b){
    while(b){
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}
ll divisorCount(ll n){

}
void solve()
{
    ll n , x , y;
    cin >> n >> x >> y;
    ll sum = 0;
    ll a = n / x;
    ll b = n / y;
    ll lcm = (1LL) * x / gcd(x , y) * y;
    ll m = (1LL) * n / lcm;
    if(x % y == 0){
        cout << -((1LL) * (b - a) * ((b - a) + 1) / 2) << ln;
        return;
    }
    a -= m;
    b -= m;
    ll pos = (1LL) * (n * (n + 1)) / 2 - ((n - a) * (n - a + 1)) / 2;
    ll neg = (1LL) * (b * (b + 1)) / 2;
    cout << pos  - neg << ln;
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
