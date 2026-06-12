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

vector<pii> ans;
void decomp(int n){
    for(ll p = 2 ; p * p <= n ; p++){
        if(n % p == 0){
            ll a = 0;
            while(n % p == 0){
                n /= p;
                a++;
            }
            ans.push_back({p , a});
        }
    }
    if(n > 1){
        ans.push_back({n , 1});
    }
}
ll power(int n , int a){
    ll r = 1;
    while(a--){
        r *= n;
    }
    return r;
}
void solve()
{
    ans.clear();
    int n;
    cin >> n;
    decomp(n);
    if(ans.size() == 1){
        if(ans[0].second >= 6){
            int x = ans[0].first;
            cout << "YES\n";
            cout << x << ' ' << power(x , 2) << ' ' << power(x , ans[0].second - 3) << ln;
        }
        else{
            cout << "NO\n";
            return;
        }
    }
    else if(ans.size() == 2){
        if(ans[0].second + ans[1].second <= 3){
            cout << "NO\n";
            return;
        }
        else{
            cout << "YES\n";
            cout << ans[0].first << ' ' << ans[1].first << ' ';
            cout << (power(ans[0].first , ans[0].second - 1)) * (power(ans[1].first , ans[1].second - 1));
            cout << ln;
        }
    }
    else{
        cout << "YES\n";
        cout << power(ans[0].first , ans[0].second) << ' ' << power(ans[1].first , ans[1].second) << ' ';
        ll x = 1;
        for(int i = 2 ; i < ans.size() ; i++){
            x *= power(ans[i].first , ans[i].second);
        }
        cout << x << ln;
    }
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