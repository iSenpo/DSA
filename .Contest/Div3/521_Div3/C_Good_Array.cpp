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

const int N  = 1e7 + 10;
vector<int> cnt(N , 0);
//always check input!!!

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans;
    ll sum = 0;
    fo(i , n){
        cin >> a[i];
        sum += a[i];
        cnt[a[i]] += 1;
    }
    for(int i = 0 ; i < n ; ++i){
        ll k = sum - a[i];
        if(k%2 == 1)
            continue;
        else
            k /= 2;
        if(k > 1e6)
            continue;
        if(cnt[k] >= 1){
            if(a[i] == k && cnt[k] == 1){
                continue;
            }
            ans.pb(i + 1);
        }
    }
    cout << sz(ans) << ln;
    for(int i : ans){
        cout << i << ' ';
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