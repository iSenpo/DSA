#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll , ll>
#define ln '\n'
#define fo(i, n) for(ll i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (ll)(x).size()
#define pb(x) push_back(x)

void solve()
{
    ll n , k;
    cin >> n >> k;
    ll a[n];
    ll m = n / k;
    vector<ll> cnt(k , 0);
    vector<ll> fre;
    vector<vector<int>> input(k);
    fo(i , n){
        cin >> a[i];
        ll j = a[i] % k;
        cnt[j]++;
        input[j].pb(i);
    }
    ll ans = 0;
    for(int p : {1 , 2}){
        fo(i , k){
            while(cnt[i] > m){
                cnt[i]--;
                int ind = input[i].back();
                input[i].pop_back();
                fre.pb(ind);
            }
            while(cnt[i] < m && !fre.empty()){
                cnt[i]++;
                int j = fre.back();
                fre.pop_back();
                ll r = a[j] % k;
                ll inc = (i - r + k) % k;
                a[j] += inc;
                ans += inc;
            }
        }
    }
    
    cout << ans << ln;
    for(ll i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*------------------------------------*/
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check ll overflow