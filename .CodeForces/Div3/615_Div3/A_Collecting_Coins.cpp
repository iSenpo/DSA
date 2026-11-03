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
    ll a , b , c , n;
    cin >> a >> b >> c >> n;
    ll ans = a +b + c + n;
    ll t = max(a , max(b , c));
    if(a < t && (t - a) <= n){
        n -= (t - a);
        a = t;
    }
    if(b < t && (t - b) <= n){
        n -= (t - b);
        b = t;
    }
    if(c < t && (t - c) <= n){
        n -= (t - c);
        c = t;
    }
    if(a == b && a == c && a == t && n%3 == 0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
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