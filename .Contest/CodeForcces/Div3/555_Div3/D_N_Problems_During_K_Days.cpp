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
    ll n , k;
    cin >> n >> k;
    ll Min = 0;
    vector<int> a(k , 0);
    fo(i , k){
        Min += (1 + i);
        a[i] = (1 + i); 
    }
    if(Min > n){
        cout << "NO\n";
        return;
    }
    int cnt = 0;
    while(Min + k <= n){
        Min += k;
        cnt++;
    }
    fo(i , k){
        a[i] += cnt;
    }
    int need = n - Min;
    fo(i , 100){
        if(!need)
                break;
        for(int i = k - 1 ; i >= 1 ; i--){
            int t = min((a[i - 1] * 2) - a[i] , need);
            a[i] += t;
            need -= t;
            if(!need)
                break;
        }
    }
    if(need == 0){
        cout << "YES\n";
        for(int i : a)
            cout << i << ' ';
        cout << ln;
    }
    else{
        cout << "NO\n";
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
