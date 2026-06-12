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
    vector<int> b;
    fo(i , n) cin >> a[i];
    b.pb(a[0]);
    for(int i = 1 ; i < n ; i++){
        if(i < n - 2 && a[i + 1] < a[i]){
            b.pb(a[i + 1]);
            b.pb(a[i]);
            b.pb(a[i + 2]);
            i += 2;
        }
        else{
            b.pb(a[i]);
        }
    }
    fo(i , n) cout << b[i] << ' ';
    cout << ln;
}
int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
