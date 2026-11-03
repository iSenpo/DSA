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
const int N  = 1e7 + 10;
const int INF = 2e9 + 100;
const int MIN = -2e9 - 100;
//always check input!!!

vector<ll> primes;
vector<bool> seen(N);

void solve()
{
    ll x;
    cin >> x;
        ll l = 0;
        ll r = primes.size() - 1;
        while(l <= r){
            ll mid = (l + r) / 2;
            ll j = primes[mid] * primes[mid];
            if(j == x){
                cout << "YES\n";
                return;
            }
            if(j < x){
                l = mid + 1;
            }
            if(j > x){
                r = mid - 1;
            }
        }
    cout << "NO\n";
}
void prm(){
    for(int i = 2 ; i <= N ; i++){
        if(seen[i]){
            continue;
        }
        primes.pb(i);
        seen[i] = 1;
        for(int j = i + i ; j <= N ; j += i){
            seen[j] = 1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    prm();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
