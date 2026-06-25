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
    int a[n] , b[n];
    fo(i , n) cin >> a[i];
    fo(i , n) cin >> b[i];
    vector<pii> ans;
    int cnt = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        bool end = true;
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(a[j] > a[j + 1]){
                end = false;
                swap(a[j] , a[j + 1]);
                cnt++;
                ans.push_back({1 , j + 1});
            }
        }
        if(end){
            break;
        }
    }
    for(int i = 0 ; i < n - 1 ; i++){
        bool end = true;
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(b[j] > b[j + 1]){
                end = false;
                swap(b[j] , b[j + 1]);
                cnt++;
                ans.push_back({2 , j + 1});
            }
        }
        if(end){
            break;
        }
    }
    fo(i , n){
        if(a[i] > b[i]){
            cnt++;
            swap(a[i] , b[i]);
            ans.push_back({3 , i + 1});
        }
    }
    cout << cnt << ln;
    fo(i , cnt){
        cout << ans[i].first << ' '  << ans[i].second << ln;
    }
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
