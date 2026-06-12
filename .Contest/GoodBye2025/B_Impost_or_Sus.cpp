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
    string s;
    cin >> s;
    int n = sz(s);
    int ans = 0;
    int x = 0;
    if(s[0] != 's'){
        ans++;
        s[0] = 's';
    }
    if(s[n - 1] != 's'){
        ans++;
        s[n - 1] = 's';
    }
    vector<int> ind;
    fo(i , n){
        if(s[i] == 's'){
            ind.pb(i);
        }
    }
    for(int j = 0 ; j < ind.size() - 1 ; j++){
        int cnt = 0;
        for(int i = ind[j] + 1 ; i < ind[j + 1] ; i++){
            cnt++;
            if(cnt%2 == 0){
                if(s[i] == 'u') ans++;
            }
        }
    }
    cout << ans << ln;
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
