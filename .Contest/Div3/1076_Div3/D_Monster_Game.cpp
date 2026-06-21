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
    int n , j = 0;
    cin >> n;
    int a[n] , b[n + 1];
    fo(i , n) cin >> a[i];
    fo(i , n) cin >> b[i];
    sort(a , a + n);
    ll level = 0;
    int cnt = 0;
    fo(i , n){
        cnt++;
        if(cnt == b[j]){
            level++;
            j++;
            cnt = 0;
        }
    }
    b[j] = cnt + 1;
    ll Max = 0;
    fo(i , n){
        if(b[j] == 0){
            j--;
            level--;
        }
        b[j]--;
        Max = max(Max , level * a[i]);
    }
    cout << Max << ln;
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
