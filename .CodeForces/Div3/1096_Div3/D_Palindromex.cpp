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

int n;
vector<int> a;
ll exp(int l , int r){
    ll t = 1;
    int pl = l , pr = r;
    unordered_set<int> st;
    st.insert(0);
    while(pl <= pr){
        if(a[pl] != a[pr]){
            return 1;
        }
        st.insert(a[pl]);
        pl++;
        pr--;
    }
    pl = l , pr = r;
    while(pl >= 0 && pr < (2 * n)){
        if(a[pl] != a[pr]){
            break;
        }
        st.insert(a[pl]);
        pl--;
        pr++;
    }
    for(ll i = 0 ; i <= n ; i++){
        if(st.find(i) == st.end()){
            t = max(t , i);
            break;
        }
    }
    return t;
}
void solve()
{
    cin >> n;
    a.resize(2 * n);
    fo(i , 2*n) cin >> a[i];
    ll ans = 1;
    int l = 0 , r = 0;
    fo(i , 2 * n){
        if(a[i] == 0){
            l = i;
            break;
        }
    }
    for(int i = l + 1 ; i < 2 * n ; i++){
        if(!a[i]){
            r = i;
            break;
        }
    }
    cout << max({exp(l , l) , exp(r , r) , exp(l , r)}) << ln;   
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
