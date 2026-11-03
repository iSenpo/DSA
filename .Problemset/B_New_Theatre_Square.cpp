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
    int n , m , x , y;
    cin >> n >> m >> x >> y;
    char a[n][m];
    fo(i , n)
        fo(j , m)
            cin >> a[i][j];

    ll ans = 0;
    fo(i , n){
        fo(j , m){
            if(a[i][j] == '.'){
                if(j <= m - 2){
                    if(a[i][j] == '.' && a[i][j + 1] == '.' && y < (2*x)){
                        ans += y;
                        a[i][j + 1] = '*';
                    }
                    else{
                        ans += x;
                    }
                }
                else{
                    ans += x;
                }
            }
        }
    }  
    cout << ans << ln; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow