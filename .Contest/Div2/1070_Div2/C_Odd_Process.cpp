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
    ll n;
    cin >> n;
    vector<ll> o , e;
    fo(i , n){
        ll a;
        cin >> a;
        if(a % 2 == 0){
            e.pb(a);
        }
        else{
            o.pb(a);
        }
    }
    sort(all(o));
    sort(all(e));
    if(o.empty()){
        fo(i , n) cout << 0 << ' ';
        cout << ln;
        return;
    }
    if(e.empty()){
        fo(i , n){
            if(i%2 == 0){
                cout << o.back() << ' ';
            }
            else{
                cout << 0 << ' ';
            }
        }
        cout << ln;
        return;
    }
    vector<ll> ans(n);
    ll sizee = e.size();
    ll k = e.size() + 1;
    ll Mine = e[0];
    ll Maxo = o.back();
    ll Max = 0;
    ans[0] = Maxo;
    for(ll i = 1 ; i < k; i++){
        ans[i] = ans[i - 1] + e.back();
        e.pop_back();
        Max = max(Max , ans[i]);
    }
    ll x = 1;
    if(sizee > 1){
        for(ll i = k; i < n ; i++){
            if(x == 1){
                ans[i] = Max - Mine;
            }
            else{
                ans[i] = Max;
            }
            x = 1 - x;
        }
    }
    else{
        for(ll i = k; i < n ; i++){
            if(x == 1){
                if(o.size() >= i + 1){
                    ans[i] = Maxo;
                }
                else{
                    ans[i] = 0;
                }
            }
            else{
                ans[i] = Max;
            }
            x = 1 - x;
        }
    }
    if(n % 2 == sizee % 2){
        ans[n - 1] = 0;
    }
    for(ll i : ans){
        cout << i << ' ';
    }
    cout << ln;
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