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

void solve()
{
    int n , m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = "0" + s;
    int a[m];
    fo(i , m) cin >> a[i];
    vector<vector<int>> cnt(n + 1 , vector<int>(26 , 0));
    for(int i = 1 ; i <= n ; i++){
        cnt[i][s[i] - 'a']++;
        for(int j = 0 ; j < 26 ; j++){
            cnt[i][j] = cnt[i][j] + cnt[i - 1][j];
        }
    }
    map<char , int> ans;
    for(int i = 0 ; i < 26 ; i++){
        ans['a' + i] += cnt[n][i];
    }
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < 26 ; j++){
            ans['a' + j] += cnt[a[i]][j];
        }
    }
    for(int i = 0 ; i < 26 ; i++){
        cout << ans['a' + i] << ' ';
    }
    cout << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow