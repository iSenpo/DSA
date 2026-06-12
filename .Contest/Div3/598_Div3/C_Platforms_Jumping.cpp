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
    int n , m , d;
    cin >> n  >> m >> d;
    int a[m];
    ll sum = 0;
    fo(i , m){
         cin >> a[i];
         sum += a[i];
    }
    ll water = n - sum;
    vector<int> ans(n , 0);
    int cnt = 0;
    fo(i , m){
        if(water - d < 0){
            cnt += (water);
            water = 0;
        }
        else{
            cnt += d - 1;
            water -= (d - 1);
        }
        while(a[i] > 0 && cnt < n){
            ans[cnt] = i + 1;
            a[i]--;
            cnt ++;
        }
    }
    if((m + 1)*(d - 1) + sum >= n){
        cout << "YES\n";
        for(int i : ans){
            cout << i << ' ';
        }
        cout << ln;
    }
    else{
        cout << "NO\n";
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