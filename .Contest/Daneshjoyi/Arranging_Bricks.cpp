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

const int N  = 2001;
//always check input!!!
vector<vector<ll>> memo(N , vector<ll>(N , -1));
int n;
ll dp(int w , int h , int t){
    if(t == n && memo[w][h] == -1){
        memo[w][h] = 1;
        return 1;
    }
    if(t > n){
        return 0;
    }
    if(memo[w][h] != -1){
        return memo[w][h];
    }
    memo[w][h] = (dp(w + 1 , h , t + h) + dp(w , h + 1 , t + 1)) % MOD;
    return memo[w][h];
}
void solve()
{
    cin >> n;
    dp(1 , 1 , 1);
    fo(i , 5){
        fo(j , 5){
            cout << memo[i][j] << ' ';
        }
        cout << ln;
    }
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