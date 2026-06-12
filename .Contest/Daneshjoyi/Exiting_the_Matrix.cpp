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
    int n , s , e , u , d;
    cin >> n >> s >> e >> u >> d;
    ll ans = 0;
    if(s == e){
        cout << 0 << ln;
        return ;
    }
    if(s < e){
        int dif = u - d;
        if(u == 0){
            cout << "use the stairs\n";
            return;
        }
        while(s + u <= e && s + u <= n){
            s += u;
            ans++;
        }
        if(dif > 0){
            while(s + dif <= e && s + dif <= n){
                s += dif;
                ans += 2;
            }
        }
        if(s == e){
            cout << ans << ln;
        }
        else{
            cout << "use the stairs\n";
        }
        return;
    }
    else{
        int dif = u - d;
        if(d == 0){
            cout << "use the stairs\n";
            return;
        }
        while(s - d >= e && s - d >= 1){
            s -= d;
            ans++;
        }
        if(dif < 0){
            while(s + dif >= e && s + dif >= 1){
                s += dif;
                ans += 2;
            }
        }
        if(s == e){
            cout << ans << ln;
        }
        else{
            cout << "use the stairs\n";
        }
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