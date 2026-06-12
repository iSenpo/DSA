#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define mt(x , y , z) make_tuple(x , y , z)

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;

const int N  = 2e5 + 10;
//always check input!!!

map<pair<int , pair<int , int>> , bool> memo;

ll dp(int a , int b , int c){
    vector<int> s = {a , b , c};
    sort(all(s));
    if(s[0] + s[1] <= s[2]){
        return 0;
    }
    if(memo[{s[0] , {s[1] , s[2]}}]){
        return 0;
    }
    memo[{s[0] , {s[1] , s[2]}}] = true;
    return 1 + dp(s[0] + 1 , s[1] - 1 , s[2]) + dp(s[0] + 2 , s[1] -1 , s[2] - 1);
}
void solve()
{
    int n;
    cin >> n;
    int d = (n - 1)/2;
    ll ans = 0;
    cout << 1LL*dp(n - (2 * d) , d , d);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow