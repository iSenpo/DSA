#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define pll pair<ll , ll>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define	set_dec(x) cout << fixed << setprecision(x);
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;
const int N  = 2e5 + 10;
const int INF = 2e9 + 100;
const int MIN = -2e9 - 100;
//always check input!!!

void solve()
{
    int n;
    cin >> n;
    int a[n];
    fo(i , n) cin >> a[i];
    int cnt0 = count(a , a + n , 0) , cnt1 = count(a , a + n , 1);
    if(cnt0 == 0){
        cout << "YES\n";
        fo(i , n) cout << 'A';
        cout << ln;
        return;
    }
    if(cnt0 == 1){
        cout << "NO\n";
        return;
    }
    vector<char> ans(n , 'C');
    int shift = 0;
    fo(i , n){
        if(a[i] == 0){
            if(shift){
                ans[i] = 'A';
                shift = 1 - shift;
            }
            else{
                ans[i] = 'B';
                shift = 1 - shift;
            }
        }
    }
    cout << "YES\n";
    for(char c : ans){
        cout << c;
    }
    cout << ln;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
