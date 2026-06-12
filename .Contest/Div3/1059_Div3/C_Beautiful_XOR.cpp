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
    int a , b;
    cin >> a >> b;
    if(a == b){
        cout << 0 << ln;
        return;
    }
    map<int , bool> bitb;
    map<int , bool> bita;
    vector<int> on;
    vector<int> off;
    int bigb = 0;
    int biga = 0;
    for(int i = 30 ; i >= 0 ; --i){
        int j = (1 << i);
        if((b & j) != 0){
            bitb[j] = true;
            bigb = max(bigb , j);
        }
        if((a & j) != 0){
            bita[j] = true;
            biga = max(biga , j);
        }
        if(bitb[j] && !bita[j]){
            on.pb(j);
        }
        if(!bitb[j] && bita[j]){
            off.pb(j);
        }
    }
    if(biga < bigb){
        cout << -1 << ln;
        return;
    }
    int ans = sz(on) + sz(off);
    if(ans > 100){
        cout << -1 << ln;
        return;
    }
    cout << ans << ln;
    for(int i : on){
        cout << i << ' ';
    }
    for(int i : off){
        cout << i << ' ';
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