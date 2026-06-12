#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;

const int N  = 1e5 + 500;
int arr[N];

inline int in(){
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int n = in();
    string s;
    cin >> s;
    ll ans = LLONG_MAX;
    for(char target : {'a' , 'b'}){
        vector<int> positions;
        for(int i = 0 ; i < n ; ++i){
            if(s[i] == target){
                positions.pb(i);
            }
        }
        if(positions.empty()){
            cout << 0 << ln;
            return;
        }
        int mid  = positions[sz(positions)/2];
        ll cur = 0;
        for(int i = 0 ; i < sz(positions) ; ++i){
            cur += abs(mid - sz(positions)/2 + i - positions[i]);
        }
        ans = min(ans , cur);
    }
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = in();
    while(t--){
        solve();
    }
    return 0;
}