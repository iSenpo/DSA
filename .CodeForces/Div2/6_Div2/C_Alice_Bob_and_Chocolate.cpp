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
    int n;
    cin >> n;
    int a[n];
    fo(i , n) cin >> a[i];
    vector<ll> l(n + 1 , 0) , r(n + 1 , 0);
    for(int i = 0 ; i < n ; i++){
        l[i + 1] = l[i] + a[i];
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        r[i] = r[i + 1] + a[i]; 
    }
    int ptl = 1 , ptr = n - 1;
    int ans1 = 1 , ans2 = 1;
    if(n == 1){
        cout << 1 << ' ' << 0 << ln;
        return;
    }
    while(ptl < ptr){
        if(l[ptl] <= r[ptr]){
            ptl++;
            ans1++;
        }
        else{
            ptr--;
            ans2++;
        }
    }
    cout << ans1 << ' ' << ans2;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
