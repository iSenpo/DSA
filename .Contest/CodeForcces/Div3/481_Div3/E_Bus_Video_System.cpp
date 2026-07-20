#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;

const int N  = 1e5 + 500;
int arr[N];

inline int in(){
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int n = in();
    ll w = in();
    ll a[n];
    fo(i , n) cin >> a[i];
    vector<ll> ps(n + 1 , 0);
    ll Min = 0;
    ll Max = w;
    for(int i = 0; i < n ; ++i){
        ps[i] += a[i];
        ps[i + 1] = ps[i];
        //
        Max = min(Max , w - ps[i]);
        Min = max(Min , 0 - ps[i]);
    }
    int ans = Max - Min  + 1;
    if(ans <= 0){
        cout << 0 << ln;
    }
    else{
        cout << ans << ln;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //t = in();
    while(t--){
        solve();
    }
    return 0;
}