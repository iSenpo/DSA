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
    vector<pii> a(n);
    fo(i , n){
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(all(a));
    vector<int> ind;
    ind.pb(0);
    ll sum = 0;
    for(int i = n - 1 ; i >= n - k ; --i){
        ind.pb(a[i].second);
        sum += a[i].first;
    }
    sort(all(ind));
    cout << sum << ln;
    for(int i = 1; i < ind.size() - 1 ; ++i){
        cout << ind[i] - ind[i - 1] << ' ';
    }
    cout << n - ind[sz(ind)-2];
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