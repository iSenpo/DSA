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



void solve()
{
    int n , k;
    cin >> n >> k;
    string ans;
    fo(i , n) ans += 'a';
    int cnt = 0;
    int s = 1;
    int d = 0;
    while(s + d< k){
        d++;
        s += d;
    }
    ans[n - 2 - d] = 'b';
    ans[n - 1 - k + s] = 'b';
    //cerr << s << ' ' << d << ln;
    cout << ans << ln;
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