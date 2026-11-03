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

const int MIN = -1e9 - 10;
void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    ll a[n];
    ll left[n] , right[n];
    fo(i , n){
        cin >> a[i];
        left[i] = a[i];
        right[i] = a[i];
    } 
    ll b[n];
    fo(i , n) cin >> b[i];
    ll ans = MIN;
    
    ll Max1 = a[0];
    left[0] = a[0];
    for(int i = 1; i < n ; i++){
        Max1 = max(a[i] , Max1 + a[i]);
        left[i] = Max1;
    }
    ll Max2 = a[n - 1];
    right[n - 1] = a[n - 1];
    for(int i = n - 2 ; i >= 0 ; i--){
        Max2 = max(a[i] , Max2 + a[i]);
        right[i] = Max2;
    }
    for(int i = 0 ; i < n ; i++){
        ll l = 0 ;
        if(i > 0){
            l = max(0LL , left[i - 1]);
        }
        ll r = 0;
        if(i < n - 1){
            r = max(0LL ,right[i + 1]);
        }
        ans = max(ans , a[i] + b[i] + l + r);
    }
    if(k%2 == 1){
        cout << ans << ln;
    }
    else{
        ll Max = a[0];
        ll curr = a[0];
        for(int i = 1; i < n ; i++){
            curr = max(a[i] , a[i] + curr);
            Max = max(Max , curr);
        }
        cout << Max << ln;
    }
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