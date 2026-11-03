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

void solve()
{
    int n;
    cin >> n;
    int a[n];
    ll ans = 0;
    fo(i , n) cin >> a[i];
    int cnt1 = 0 , cnt2 = 0;
    fo(i , n){
        if(a[i]%3 == 0){
            ans++;
        }
        else if(a[i]%3 == 1){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
    int t = min(cnt1 , cnt2);
    ans += t;
    //cerr << t << ln;
    cnt1 -= t;
    cnt2 -= t;
    int d1 = cnt1/3;
    ans += d1;
    cnt1 -= (d1 * 3);
    while(cnt1 >= 3){
        ans++;
        cnt1 -= 3;
    }
    int d2 = cnt2/3;
    ans += d2;
    cnt2 -= (d2 * 3);
    while(cnt2 >= 3){
        ans++;
        cnt2 -= 3;
    }
    cout << ans << ln;
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