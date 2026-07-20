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

ll gcd(ll a , ll b){
    while(b){
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}
void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    fo(i , n) cin >> a[i];
    bool fard = false;
    bool zoj = false;
    fo(i , n){
        if(a[i] % 2 == 0){
            zoj = 1;
        }
        else {
            fard = 1;
        }
    }
    if(zoj && fard){
        cout << 2 << ln;
        return;
    }
    for(int i = 1 ; i <= 70 ; i++){
        ll j = (1 << i);
        set<ll> st;
        fo(p , n){
            st.insert(a[p] % j);
        }
        if(st.size() == 2){
            cout << j << ln;
            return;
        }
    }
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
