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

vector<int> nums;
bool check(ll n){
    vector<bool> vis(10 , false);
    int cnt = 0;
    while(n){
        int d = n % 10;
        if (!vis[d]) {
            vis[d] = true;
            cnt++;
            if (cnt > 2) return false;
        }
        n /= 10;
    }
    return true;
}
void dfs(ll cur, int a, int b) {
    if(cur > 1e9) return;

    if(cur >= 2){
        nums.push_back(cur);
    }
    ll x = cur * 10 + a;
    if(x <= 1e9){
        dfs(x , a , b);
    }
    if(a != b){
        x = cur * 10 + b;
        if(x <= 1e9){
            dfs(x , a , b);
        }
    }
}
void solve()
{
    string x;
    cin >> x;
    int L = (int)x.size();
    string y = "1" + string(L - 1, '0') + "1";
    cout << y << '\n';
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
