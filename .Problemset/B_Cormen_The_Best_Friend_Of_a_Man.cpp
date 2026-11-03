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
    int n , k;
    cin >> n >> k;
    int a[n];
    fo(i , n) cin >> a[i];
    int today, tomor;
    vector<int> ans;
    ans.pb(a[0]);
    ll out = 0;
    for(int i = 0 ; i < n - 1; i++){
        if(a[i] >= k){
            today = k;
        }
        else{
            today = a[i];
        }
        if(a[i + 1] >= k){
            tomor = k; 
        }
        else{
            tomor = a[i + 1];
        }
        int t = today + tomor;
        if(t < k){
            a[i + 1] += k - t;
            out += k - t;
        }
        ans.push_back(a[i + 1]);
    }
    cout << out << ln;
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