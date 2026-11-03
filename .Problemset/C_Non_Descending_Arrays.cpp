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

const int N = 2e5 + 10;
const int MOD = 998244353;
int n;
vector<int> a(101 , 0), b(101 , 0);
vector<vector<int>> memo(101, vector<int>(2, -1));

ll dp(int i , bool swaped){
    if(i == n){
        if(!swaped){
            if(a[i] >= a[i - 1] && b[i] >= b[i - 1]){
                return 1;
            } else {
                return 0;
            }
        }
        else{
            if(a[i] >= b[i - 1] && b[i] >= a[i - 1]){
                return 1;
            } else {
                return 0;
            } 
        }
    }
    if(memo[i][swaped] != -1){
        return memo[i][swaped];
    }
    if(swaped){
        if(a[i] < b[i - 1] || b[i] < a[i - 1]){
            return memo[i][swaped] = 0;
        }
    }
    else{
        if(a[i] < a[i - 1] || b[i] < b[i - 1]){
            return memo[i][swaped] = 0;
        }
    }
    return memo[i][swaped] = (dp(i + 1 , true) + dp(i + 1 , false)) % MOD;
}

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for (int i = 0; i <= n; ++i) {
        fill(memo[i].begin(), memo[i].end(), -1);
    }
    cout << (dp(1 , true) + dp(1 , false)) % MOD << ln;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;

    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
