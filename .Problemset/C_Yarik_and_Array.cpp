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
vector<ll> a;
ll kadane(int l , int r){
    ll sum = a[l];
    ll res = a[l];
    for(int i = l + 1 ; i <= r ; i++){
        sum = max(sum + a[i] , a[i]);
        res = max(res , sum);
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    a = vector<ll>(n + 1);
    fo(i , n) cin >> a[i];
    a[n] = a[n - 1];
    ll ans = a[0];
    int ptl = 0 , ptr = 0;
    while(ptr < n){
        while(ptr < n && ((int)(abs(a[ptr])%2) != (int)(abs(a[ptr + 1])%2))){
            ptr++;
        }
        ans = max(ans , kadane(ptl , ptr));
        ptr++;
        ptl = ptr;
    }
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
