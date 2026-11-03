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
    vector<pii> odd;
    vector<pii> even;
    int sumO = 0;
    int sumE = 0;
    int input;
    odd.push_back({0 , -1});
    even.push_back({0 , - 1});
    fo(i , n){
        cin >> input;
        if(i% 2 == 0){
            sumO += input;
            odd.push_back({sumO , i});
        }
        else{
            sumE += input;
            even.push_back({sumE , i});
        }
    }
    int ans = 0;
    for(int i = 1 ; i < sz(odd) ; ++i){
        int odds = odd[i - 1].first + even[sz(even) - 1].first - even[i - 1].first;
        int evens = even[i - 1].first + odd[sz(odd) - 1].first - odd[i].first;
        if(odds == evens){
            ans++;
        }    
    }
    for(int i = 1 ; i < sz(even) ; ++i){
        int odds = odd[i].first + even[sz(even) - 1].first - even[i].first;
        int evens = even[i - 1].first + odd[sz(odd) - 1].first - odd[i].first;
        if(odds == evens){
            ans++;
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