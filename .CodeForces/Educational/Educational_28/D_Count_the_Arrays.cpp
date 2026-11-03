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

int MOD = 998244353;

const int N  = 2e5 + 10;
//always check input!!!

void solve()
{
    int n , m;
    cin >> n >> m;
    ll ans = 0;
    vector<int> a;
    int temp = m;
    while(--temp){
        a.push_back(temp);
    }
    ll curr = 1;
    for(int i = 0 ; i < n - 2 ; i++){
        curr = (curr * a[i]) % MOD;
    }
    ans = (ans + curr) % MOD;
    int t = n - 2;
    for(int i = t ; i < sz(a) ; i++){
        curr /= a[i - t];
        curr = (curr * a[i]) % MOD;
        ans = (ans + curr) % MOD;
    }
    cout << ans << ln;
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