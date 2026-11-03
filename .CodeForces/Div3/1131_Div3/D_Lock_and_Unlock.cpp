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
   int n;
   cin >> n;
   int a[n];
   fo(i , n) cin >> a[i];
   sort(a , a + n);
   int l = 0 , r = n - 1;
   int op = 0;
   ll cost = 0;
   while(l < r){
        while(l < n - 1 && a[l] == a[l + 1]){
            l++;
        }
        while(r > 1 && a[r] == a[r - 1]){
            r--;
        }
        if(l >= r) break;
        if((l + 1) < (n - r)){
            ll d = a[l + 1] - a[l];
            op += d;
            cost += ((l + 1) * d);
            l++;
        }
        else{
            ll d = a[r] - a[r - 1];
            op += d;
            cost += ((n - r) * d);
            r--;
        }
   } 
   cout << cost << ' ' << op << ln;
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
