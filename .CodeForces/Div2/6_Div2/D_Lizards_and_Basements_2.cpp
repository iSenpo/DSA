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


int n, x, y;
int ans = INF;

vector<int> a;
vector<int> shot;
vector<int> best;

bool check(){
    for(int i = 1; i < n - 1; i++){
        ll damage = (x * shot[i]) + (y * shot[i - 1]) + (y * shot[i + 1]);
        if(a[i] >= damage){
            return false;
        }
    }
    if(y * shot[1] <= a[0]){
        return false;
    }
    if(y * shot[n - 2] <= a[n - 1]){
        return false;
    }
    return true;
}

void dfs(int i, int sum){
    if(sum >= ans){
        return;
    }
    if(i == n - 1){
        if(check()){
            ans = sum;
            best = shot;
        }
        return;
    }
    int limit = max({(a[i - 1] / y) + 1 , (a[i] / x) + 1 , (a[i + 1] / y) + 1});
    for(int j = 0; j < limit ; j++){
        shot[i] = j;
        dfs(i + 1, sum + j);
    }
    shot[i] = 0;
}

void solve(){
    cin >> n >> x >> y;
    
    a.resize(n);
    shot.assign(n, 0);
    best = shot;

    fo(i, n) cin >> a[i];

    dfs(1, 0);
    
    cout << ans << ln;
    for(int i = 1; i < n - 1; i++){
        while(best[i]--){
            cout << i + 1 << ' ';
        }
    }
    cout << ln;
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
