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

ll power(ll a , ll p){
    ll r = 1;
    while(p--){
        r *= a;
    }
    return r;
}
void solve()
{
    int n;
    cin >> n;
    ll maxx = power(2 , n);
    vector<set<ll>> pw(n);
    for(int i = 1 ; i < maxx ; i++){
        if(i % 2 == 1){
            int cnt = 0;
            ll t = i;
            vector<bool> mark(20 , false);
            for(int j = 20 ;  j >= 0 ; j--){
                ll k = power(2 , j);
                if(t - k >= 0){
                    mark[j] = true;
                    t -= k;
                }
            }
            for(int i = 0 ; i < 20 ; i++){
                if(!mark[i]){
                    break;
                }
                else{
                    cnt++;
                }
            }
            pw[cnt - 1].insert(i);
        }
    } 
    vector<ll> ans;
    for(int i = n - 1; i >= 0 ; i--){
        while(!pw[i].empty()){
            ans.push_back(*pw[i].begin());
            pw[i].erase(pw[i].begin());
        }
    }
    for(int i = 0 ; i < maxx ; i++){
        if(i % 2 == 0){
            ans.push_back(i);
        }
    }
    for(int i : ans){
        cout << i << ' ';
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
