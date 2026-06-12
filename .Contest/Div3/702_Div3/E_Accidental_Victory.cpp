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

void solve()
{
    ll n;
    cin >> n;
    vector<pll> a;
    fo(i , n){
        ll x;
        cin >> x;
        a.push_back({x , i + 1}); 
    }
    vector<ll> ans;
    sort(all(a));
    ans.push_back(a[n - 1].second);
    vector<ll> ps(n + 1 , 0);
    fo(i , n){
        ps[i + 1] = ps[i] + a[i].first;
    }
    for(int i = n - 2 ; i >= 1 ; i--){
        if(ps[i + 1] >= a[i + 1].first){
            ans.push_back(a[i].second);
        }
        else{
            break;
        }
    }
    if(a[0].first >= a[1].first && ans.back() == a[1].second){
        ans.push_back(a[0].second);
    }
    sort(all(ans));
    cout << ans.size() << ln;
    for(int i : ans){
        cout << i << ' ';
    }
    cout << ln;
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
