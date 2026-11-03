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
    int n , m;
    cin >> n >> m;
    int Min[n] , Max[n];
    if(n == 1 && m == 0){
        cout << "0 0\n";
        return;
    }
    if(m == 0){
        cout << "-1 -1\n";
        return;
    }
    if(n * 9 < m){
        cout << "-1 -1\n";
        return;
    }
    fo(i , n) Min[i] = 0;
    Min[0] = 1;
    fo(i , n) Max[i] = 9;
    for(int i = n - 1 ; i >= 0 ; i--){
        while(accumulate(Max , Max + n , 0LL) > m && Max[i] > 0){
            Max[i]--;
        }
        while(accumulate(Min , Min + n , 0LL) < m && Min[i] < 9){
            Min[i]++;
        }
    }
    fo(i , n) cout << Min[i];
    cout << ' ' ;
    fo(i , n) cout << Max[i];
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
