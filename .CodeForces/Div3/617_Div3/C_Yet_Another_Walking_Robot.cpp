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
    int n; cin >> n;
    string s; cin >> s;
    pii c = {0 , 0} , ans = {0 , 0};
    map<pii , int> dp;
    dp[{0 , 0}] = 1;
    int Max = INF;
    fo(i , n){
        if(s[i] == 'L'){
            c.first--;
        }
        else if(s[i] == 'R'){
            c.first++;
        }
        else if(s[i] == 'U'){
            c.second++;
        }
        else if(s[i] == 'D'){
            c.second--;
        }
        if(dp[c]){
            if((i + 2) - dp[c] < Max){
                ans = {dp[c] , i + 1};
                Max = (i + 2) - dp[c];
            }
        }
        dp[c] = i + 2;
    }
    if(Max != INF){
        cout << ans.first << ' ' << ans.second << ln;
    }
    else{
        cout << -1 << ln;
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
