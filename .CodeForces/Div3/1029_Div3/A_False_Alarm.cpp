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
    int n , x;
    cin >> n >> x;
    int a[n];
    fo(i , n) cin >> a[i];
    int f = 0 , l = 0;
    fo(i , n) 
        if(a[i] == 1){
            f = i;
            break; 
        }
    for(int i = n - 1 ; i >= 0 ; i--){
        if(a[i] == 1){
            l = i;
            break;
        }
    }
    //cerr << l << ' ' << f << ln;
    if(l - f + 1 <= x){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
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
