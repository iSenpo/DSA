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
    int n , m;
    cin >> n >> m;
    ll a[n] , sum = 0;
    fo(i , n){
        cin >> a[i];
        sum += a[i];
    }
    sort(a , a + n);
    reverse(a , a + n);
    if(sum < m){
        cout << -1 << ln;
        return;
    }
    int dw = 1 , up = n;
    int ans = 0 , k;
    ll curr = 0;
    while(dw <= up){
        k = (dw + up)/2;
        curr = 0;
        for(int i = 0 ; i < n ; ++i){
            curr += max<ll>(0 , a[i] - i/k);
        }
        if(curr >= m){
            ans =  k;
            up = k - 1;
        }
        else{
            dw = k + 1;
        }
    }
    cout << ans << ln;
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