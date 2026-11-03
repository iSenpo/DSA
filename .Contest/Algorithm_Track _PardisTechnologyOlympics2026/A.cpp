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
    int a1 , b1 , c1 , a2 , b2 , c2 , a3 , b3 , c3;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2 ;
    cin >> a3 >> b3 >> c3;
    int d1 = a1 + c1 + (2 * b1);
    int d2 = a2 + c2 + (2 * b2);
    int d3 = a3 + c3 + (2 * b3);
    if(max({d1 , d2 , d3}) == d1){
        cout << 1 << ln;
    }
    else if(max({d1 , d2 , d3}) == d2){
        cout << 2 << ln;
    }
    else if(max({d1 , d2 , d3}) == d3){
        cout << 3 << ln;
    }
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
