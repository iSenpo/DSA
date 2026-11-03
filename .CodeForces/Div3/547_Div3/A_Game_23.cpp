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
const int prim[23] = {5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
//always check input!!!
bool check(ll n){
    for(int i = 0 ; i < 23 ; i++){
        if(prim[i] > n){
            break;
        }
        if(n%prim[i] == 0){
            return false;
        }
    }
    return true;
}
void solve()
{
    ll n , m;
    cin >> n >> m;
    ll d = m/n;
    if(n == m){
        cout << 0 << ln;
        return;
    }
    if(m%n != 0 || !check(d) || !(d%2 == 0 || d%3 == 0)){
        cout << -1 << ln;
        return;
    }
    ll ans = 0;
    while(d%3 == 0 && d > 1){
        d /= 3;
        ans++;
    }
    while(d%2 == 0 && d > 1){
        d /= 2;
        ans++;
    }
    cout << ans <<ln;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow