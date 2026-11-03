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
    ll n , ans = 0;
    cin >> n;
    ll a[n];
    fo(i , n) cin >> a[i];
    vector<ll> p(n , MIN);
    map<int , vector<int>> ind;
    fo(i , n - 4){
        p[i] = a[i] + a[i + 2] - a[i + 4];
        ind[p[i]].push_back(i);
    }
    fo(i , n - 4){
        int dw = 0;
        int up = ind[p[i]].size();
        int best = -1;
        while(dw <= up){
            int mid = (dw + up) / 2;
            if(ind[p[i]][mid] == i){
                if(mid + 1 < ind[p[i]].size()){
                    best = mid + 1;
                }
                break;
            }
            else if(ind[p[i]][mid] < i){
                dw = mid + 1;
            }
            else{
                up = mid - 1;
            }
        }
        if(best == -1) continue;
        else{
            ans += ind[p[i]].size() - best;
            if(p[i + 2] == p[i]) ans--;
            if(p[i + 4] == p[i]) ans--;
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
