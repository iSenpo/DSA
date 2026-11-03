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
    int Max = 0;
    vector<int> dp1(n , 1) , dp2(n , 1);
    for(int i = 1 ; i < n ; i++){
        if(a[i] > a[i - 1]){
            dp1[i] += dp1[i - 1];  
        }
        Max = max(Max , dp1[i]);
    }
    for(int i = n - 2 ; i >= 0 ; i--){
        if(a[i] < a[i + 1]){
            dp2[i] += dp2[i + 1];
        }
        Max = max(Max , dp1[i]);
    }
    for(int i = 1 ; i < n - 1 ; i++){
        if(a[i - 1] < a[i + 1]){
            Max = max(Max , dp1[i - 1] + dp2[i + 1]);
        }
    }
    cout << Max << ln;
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
