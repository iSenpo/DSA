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
    vector<int> odd , even;
    int tmp;
    fo(i , n){
        cin >> tmp;
        if(tmp%2 == 0){
            even.pb(tmp);
        }
        else{
            odd.pb(tmp);
        }
    }
    if(abs(sz(odd) - sz(even)) <= 1){
        cout << 0 << ln;
        return;
    }
    ll sum = 0;
    if(sz(odd) > sz(even)){
        sort(all(odd));
        fo(i , sz(odd) - sz(even) - 1){
            sum += odd[i];
        }
    }
    else{
        sort(all(even));
        fo(i , sz(even) - sz(odd) - 1){
            sum += even[i];
        }
    }
    cout << sum << ln;
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