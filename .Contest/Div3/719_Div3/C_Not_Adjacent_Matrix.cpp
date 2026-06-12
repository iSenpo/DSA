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
    ll n;
    cin >> n;
    if(n == 1){
        cout << 1 << ln;
        return;
    }
    if(n == 2){
        cout << -1 << ln;
        return;
    }
    int cnt = 1;
    int a[n][n];
    fo(i , n){
        for(int j = (i % 2) ; j < n ; j += 2){
            a[i][j] = cnt;
            cnt++;
        }
    }
    fo(i , n){
        for(int j = 1 - (i % 2) ; j < n ; j += 2){
            a[i][j] = cnt;
            cnt++;
        }
    }
    fo(i , n){
        fo( j , n){
            cout << a[i][j] << ' ';
        }
        cout << ln;
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
