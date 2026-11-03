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
const int INF = 1e5;
const int MIN =-1e5;
//always check input!!!
/*
1 -> left
2 -> up
3 -> right
4 -> down
*/
void solve()
{
    int n;
    cin >> n;
    int maxx = INF , maxy = INF , minx = MIN , miny = MIN;
    fo(i , n){
        int x , y , l , u , r , d;
        cin >> x >> y >> l >> u >> r >> d ;
        if(r == 0){
            maxx = min(maxx , x);
        }
        if(l == 0){
            minx = max(minx , x);
        }
        if(u == 0){
            maxy = min(maxy , y);
        }
        if(d == 0){
            miny = max(miny , y);
        }
    }
    if(maxx < minx || maxy < miny){
        cout << 0 << ln;
        return;
    }
    cout << 1 << ' ' << (maxx + minx)/2 << ' ' << (maxy + miny)/2 << ln;
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
