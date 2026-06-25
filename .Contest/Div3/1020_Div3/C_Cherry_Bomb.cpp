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
    int n , x;
    cin >> n >> x;
    int a[n] , b[n];
    fo(i , n) cin >> a[i];
    fo(i , n) cin >> b[i];
    int d = -1;
    fo(i , n){
        if(b[i] != -1){
            d = a[i] + b[i];
        }
    }
    if(d == -1){
        int Max = *max_element(a , a + n);
        int Min = *min_element(a , a + n);
        if(Min + x < Max){
            cout << 0 << ln;
            return;
        }
        cout << Min + x - Max + 1 << ln;
    }
    else{
        fo(i , n){
            if(b[i] == -1){
                if(a[i] + x < d){
                    cout << 0 << ln;
                    return;
                }
                if(a[i] > d){
                    cout << 0 << ln;
                    return;
                }
            }
            else if(a[i] + b[i] != d){
                cout << 0 << ln;
                return;
            }

        }
        cout << 1 << ln;
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
