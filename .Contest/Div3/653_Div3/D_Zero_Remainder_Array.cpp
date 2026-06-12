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
    ll a[n];
    fo(i , n) cin >> a[i];
    map<ll ,ll> cnt;
    ll Max = 0;
    fo(i, n){
        ll x = k - (a[i] % k);
        if(x == k){
            continue;
        }
        cnt[x]++;
        Max = max(Max , cnt[x]);
    }
    set<ll> st;
    if(Max == 0){
        cout << 0 << ln;
        return;
    }
    fo(i , n){
        ll x = k - (a[i] % k);
        if(cnt[x] == Max){
            st.insert(x);
        }
    }
    vector<ll> v(all(st));
    ll ans = (cnt[v[v.size() - 1]] - 1)* (1LL) * k;
    //cerr << ans << ln;
    ans = (ll)(ans)+ (ll)(v[v.size() - 1] + 1);
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