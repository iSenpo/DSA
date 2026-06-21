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
    int target = -1;
    int j = 0;
    fo(i , n){
        if(a[i] != n - i){
            target = n - i;
            //cerr << target << ln;
            j = i - 1;
            break;
        }
    }
    int i = 0;
    for(i ; i <= j ; i++){
        cout << a[i] << ' ';
    }
    if(target != -1){
        vector<int> r;
        for(i ; a[i] != target ; i++){
            r.push_back(a[i]);
        }
        r.push_back(a[i++]);
        reverse(all(r));
        for(int k : r){
            cout << k << ' ';
        }
    }
    for(i ; i < n ; i++){
        cout << a[i] << ' ';
    }
    cout << ln;

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
