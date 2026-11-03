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

void ispow2(ll n){
    for(int i = 30 ; i >= 0 ; i--){
        ll j = (1 << i);
        if((n - j) == 0){
            cout << "YES\n" << j << ln;
            return;
        }
    }
    cout << "NO\n";
    exit(0);
}
void solve()
{
    ll n , k;
    cin >> n >> k;
    if(k > n){
        cout << "NO\n";
        return;
    }
    if(k == 1){
        ispow2(n);
    }
    else{
        ll t = n;
        map<ll , ll> cnt;
        for(int i = 30 ; i >= 0 ; i--){
            ll j = (1 << i);
            if((ll)t - j >= 0){
                t -= j;
                cnt[i]++;
                k--;
            }
        }
        for(int i = 30 ; i >= 0 ; i--){
            if(k > 0 && cnt[i] > 0){
                ll m = min(k , cnt[i]);
                k -= m;
                cnt[i] -= m;
                cnt[i - 1] += (m * 2);
            }
        }
        if(k < 0){
            cout << "NO\n";
            return;
        }
        vector<ll> ans;
        for(int i = 30 ; i >= 0 ; i--){
            ll j = (1 << i);
            while(cnt[i] > 0){
                ans.push_back(j);
                cnt[i]--;
            }
        }
        sort(all(ans));
        cout << "YES\n";
        for(int i : ans){
            cout << i << ' ';
        }
        cout << ln;
    }
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