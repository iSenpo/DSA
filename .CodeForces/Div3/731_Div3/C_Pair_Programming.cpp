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
    int k , n , m;
    cin >> k >> n >> m;
    int a[n] , b[m];
    fo(i , n) cin >> a[i];
    fo(i , m) cin >> b[i];
    vector<int> ans;
    int ptn = 0 , ptm = 0;
    while(ans.size() < n + m){
        if(ptn < n && a[ptn] == 0){
            ans.push_back(a[ptn++]);
            k++;
        }
        else if(ptm < m && b[ptm] == 0){
            ans.push_back(b[ptm++]);
            k++;
        }
        else if(ptn < n && a[ptn] <= k){
            ans.push_back(a[ptn++]);
        }
        else if(ptm < m && b[ptm] <= k){
            ans.push_back(b[ptm++]);
        }
        else{
            cout << -1 << ln;
            return;
        }
    }
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
