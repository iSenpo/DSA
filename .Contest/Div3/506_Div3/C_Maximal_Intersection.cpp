#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll , ll>
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

const int N  = 2e9 + 100;
//always check input!!!

void solve()
{
    int n;
    cin >> n;
    vector<pii> a(n);
    ll l[n] , r[n];
    ll Maxl = 0 , Minr = N;
    fo(i , n){
        ll x , y;
        cin >> x >> y;
        a[i] = {x , y};
        l[i] = x;
        r[i] = y;
        Maxl = max(Maxl , x);
        Minr = min(Minr , y);
    }
    ll Max = Minr - Maxl;
    ll lmxl[n] , lmxr[n];
    ll rmnl[n] , rmnr[n];
    Minr = N;
    Maxl = 0;
    for(int i = 0 ; i < n ; i++){
        Maxl = max(Maxl , a[i].first);
        lmxl[i] = Maxl;
        Minr = min(Minr , a[i].second);
        rmnl[i] = Minr;
    }
    Minr = N;
    Maxl = 0;
    for(int i = n - 1 ; i >= 0 ;i--){
        Maxl = max(Maxl , a[i].first);
        lmxr[i] = Maxl;
        Minr = min(Minr , a[i].second);
        rmnr[i] = Minr;
    }

    for(int i = 1 ; i < n - 1 ; i++){
        Maxl = max(lmxl[i - 1] , lmxr[i + 1]);
        Minr = min(rmnl[i - 1] , rmnr[i + 1]);
        Max = max(Max , Minr - Maxl);
    }
    Maxl = lmxr[1];
    Minr = rmnr[1];
    Max = max(Max , Minr - Maxl);
    Maxl = lmxl[n - 2];
    Minr = rmnl[n - 2];
    Max = max(Max , Minr - Maxl);
    
    cout << max(Max , 0LL) << ln;
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