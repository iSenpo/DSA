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

int n;
int a[100];
int ans[100];

void find(int l = 0 , int r = n , int k = 0){
    int Max = 0 , ind = 0;
    if((l + 1) == r){
        ans[l] = k;
        return;
    }
    for(int i = l ; i < r ; i++){
        Max = max(Max , a[i]);
    }
    for(int i = l ; i < r ; i++){
        if(a[i] == Max){
            ans[i] = k;
            find(l , i , k + 1);
            find(i + 1 , r , k + 1);
            return;
        }
    }
}
void solve()
{
    cin >> n;
    fo(i , n) cin >> a[i];    
    find();
    fo(i , n) cout << ans[i] << ' ';
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
