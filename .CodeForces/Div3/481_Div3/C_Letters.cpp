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
    int m = in();
    ll a[n];
    ll b[m];
    fo(i , n) cin >> a[i];
    fo(i , m) cin >> b[i];
    ll ps[n + 1];
    ps[0] = 0;
    for(int i = 1 ; i <= n ; ++i){
        ps[i] = ps[i - 1] + a[i - 1];
    }
    int j = 1;
    fo(i , m){
        while(b[i] > ps[j]){
            j++;
        }
        cout << j << ' ' << b[i] - ps[j - 1] << ln;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //t = in();
    while(t--){
        solve();
    }
    return 0;
}