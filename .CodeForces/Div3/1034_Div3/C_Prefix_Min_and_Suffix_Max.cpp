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
    vector<int> ans(n , 0) , prefix(n) , suffix(n);
    prefix[0] = a[0];
    for(int i = 1 ; i < n ; i++){
        prefix[i] = min(prefix[i - 1] , a[i]);
    }
    suffix[n - 1] = a[n - 1];
    for(int i = n - 2 ; i >= 0 ; i--){
        suffix[i] = max(suffix[i + 1] , a[i]);
    }
    if(a[0] <= suffix[0] || a[0] >= suffix[0]) ans[0] = 1;
    if(a[n - 1] >= prefix[n - 1] || a[n - 1] <= prefix[n - 1]) ans[n - 1] = 1; 
    for(int i = 1 ; i < n - 1 ; i++){
        if(a[i] <= prefix[i] && a[i] <= suffix[i]){
            ans[i] = 1;
        }
        if(a[i] >= prefix[i] && a[i] >= suffix[i]){
            ans[i] = 1;
        }
    }
    for(int i : ans){
        cout << i ;
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
