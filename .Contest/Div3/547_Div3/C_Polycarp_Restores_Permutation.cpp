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

const int INF  = 1e8 + 10;
//always check input!!!
bool isPermution(vector<int> p){
    sort(all(p));
    fo(i , sz(p)){
        if(p[i] != i + 1){
            return false;
        }
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    int a[n - 1];
    fo(i , n - 1) cin >> a[i];
    int Min = 33;
    vector<int> ans;
    ans.pb(33);
    fo(i , n - 1){
        int x = ans[i] + a[i];
        ans.pb(x);
        Min = min(Min , x);
    }
    
    int diff = Min - 1;
    fo(i , n){
        ans[i] -= diff;
    }
    if(!isPermution(ans)){
        cout << -1 << ln;
        return;
    }
    for(int i : ans){
        cout << i << ' ' ;
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