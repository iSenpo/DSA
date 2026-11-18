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
    if(b > a) swap(a , b);
    while(b > 0){
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> ind(1001 , -1);
    int a[n];
    fo(i , n){
        cin >> a[i];
        ind[a[i]] = i;
    }
    ll ans = -1;
    for(int i = 1 ; i <= 1000 ; i++){
        for(int j = 1 ; j <= 1000 ; j++){
            if(gcd(j , i) == 1 && ind[j] != -1 && ind[i] != -1){
                ans = max(ans , (ll)ind[i] + ind[j] + 2);
            }
        }
    }
    cout << ans << ln;
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
