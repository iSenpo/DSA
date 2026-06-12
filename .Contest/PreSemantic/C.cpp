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
    ll n;
    cin >> n;
    ll a[n];
    fo(i , n) cin >> a[i];
    if(n == 2){
        ll x = min(a[0] , a[1]);
        ll y = max(a[0] , a[1]);
        if(x > 2 * (1LL) * y || y > 2 * (1LL) * x){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
        return;
    }
    ll d = abs(a[1] - a[0]);
    bool alleq = true;
    fo(i , n){
        if(a[i] != a[0]){
            alleq = false;
            break;
        }
    }
    if(alleq){
        if(a[0]%(n + 1) == 0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        return;
    }
    if(a[0] > a[1]){
        for(int i = 0 ; i < n - 1 ; i++){
            if(a[i] < a[i + 1]){
                cout << "NO\n";
                return;
            }
        }
    }
    if(a[0] < a[1]){
        for(int i = 0 ; i < n - 1 ; i++){
            if(a[i] > a[i + 1]){
                cout << "NO\n";
                return;
            }
        }
    }
    fo(i , n - 1){
        if(abs(a[i + 1] - a[i]) != d){
            cout << "NO\n";
            return;
        }
    }
    fo(i , n){
        if(a[i]%d != 0){
            //cerr <<"JOJO " << ln;
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
