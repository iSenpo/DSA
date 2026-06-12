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
ll gcd(ll a , ll b){
    while(b != 0){
        ll r = a%b;
        a = b;
        b = r;
    }
    return a;
}
void solve()
{
    int n;
    cin >> n;
    ll a[n];
    fo(i , n) cin >> a[i];
    sort(a , a + n);
    fo(i , n){
        if(a[i] % a[0] != 0){
            a[0] = gcd(a[i] , a[0]);
        }
    }
    if(a[0] == 1){
        cout << 1 << ln;
        return;
    }
    vector<ll> ans;
    for(int i = 1 ; i <= sqrt(a[0]) ; i++){
        if(a[0]%i == 0){
            ll b = a[0]/i;
            ans.pb(i);
            if(b != i){
                ans.pb(b);
            }
        }
    }
    cout << ans.size() << ln; 
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