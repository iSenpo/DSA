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
    int n , m;
    cin >> n >> m;
    int a[n] , b[m];
    fo(i , n) cin >> a[i];
    fo(i , m) cin >> b[i];
    int j = 0 , L = 0 , R = 0;
    vector<int> l(m , -1) , r(m , -1);
    fo(i , n){
        if(j >= m) break;
        if(a[i] >= b[j]){
            l[j] = i;
            j++;
        }
    }
    j = m - 1;
    for(int i = n - 1; i >= 0 ; i--){
        if(j < 0) break;
        if(a[i] >= b[j]){
            r[j] = i;
            j--;
        }
    }
    int ans = INF;
    for(int i = 1; i < m - 1 ; i++){
        if(l[i - 1] != -1 && r[i + 1] != -1 && l[i - 1] < r[i + 1]){
            ans = min(ans , b[i]);
        }
    }
    if(l[m - 1] != -1 || r[0] != -1){
        cout << 0 << ln;
        return;
    }
    if(l[m - 2] != -1){
        ans = min(ans , b[m - 1]);
    }
    if(r[1] != -1){
        ans = min(ans , b[0]);
    }
    if(ans == INF) cout << -1 << ln;
    else{
        cout << ans << ln;
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
