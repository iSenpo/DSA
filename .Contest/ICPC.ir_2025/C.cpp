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

const int bb[3] = {3 , 2 , 1};

void solve()
{
    int n;
    cin >> n;
    int a , b , c;
    cin >> a >> b >> c;

    int p = 0;
    ll ans = 0;
    while(n > 0){
        if(n - bb[p] != a && n - bb[p] != b && n - bb[p] != c){
            n -= bb[p];
            p = 0;
            ans++;
        }
        else{
            p++;
        }
        if(p == 3){
            if(n != 0){
                cout << -1 << ln;
                return;
            }
        }
    }    
    cout << ans << ln;
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