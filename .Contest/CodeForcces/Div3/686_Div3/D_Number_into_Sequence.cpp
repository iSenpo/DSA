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
    map<int , ll> cnt;
    vector<ll> v;
    vector<ll> ans;
    ll nn = n;
    ll Max = 0;
    ll t = sqrt(n);
    for(ll i = 2 ; i <= t ; i++){
        if(n % i == 0){
            v.pb(i);
        }
        else{
            continue;
        }
        while(n % i == 0){
            cnt[i]++;
            n /= i;
        }
        Max = max(Max , cnt[i]);
        if(n == 1){
            break;
        }
    }
    if(v.empty()){
        cout << 1 << ln << nn << ln;
        return;
    }
    if(n > 1){
        v.push_back(n);
        cnt[n]++;
        Max = max(Max , cnt[n]);
    }
    for(ll i : v){
        if(cnt[i] == Max){
            while(cnt[i] > 0){
                ans.push_back(i);
                cnt[i]--;
            }
            break;
        }
    }
    for(ll i : v){
        ll ptr = ans.size() - 1;
        while(cnt[i] > 0){
            ans[ptr] = ans[ptr] * (1LL) * i;
            ptr--;
            cnt[i]--;
        }
    }
    cout << ans.size() << ln;
    for(ll i : ans){
        cout << i << ' ' ;
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