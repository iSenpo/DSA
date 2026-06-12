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
    int a[n];
    fo(i , n) cin >> a[i];
    if(k == 2){
        for(int i = 0; i < n - 1 ; i++){
            if(a[i] == a[i + 1]){
                if(a[i + 1] == 1){
                    a[i + 1] = 2;
                }
                else{
                    a[i + 1] = 1;
                }
            }
        }
        fo(i , n) cout << a[i] << ' ';
        return;
    }
    for(int i = 0 ; i < n - 2 ; i++){
        if(a[i] == a[i + 1]){
            for(int j = 1 ; j <= k ; j++){
                if(j != a[i + 1] && j != a[i + 2]){
                    a[i + 1] = j;
                    break;
                }
            }
        }
    }
    if(a[n - 2] == a[n - 1]){
        int c;
        for(int j = 1 ; j <= k ; j++){
            if(j != a[n - 2] && j != a[n - 1]){
                c = j;
                break;
            }
        }
        a[n - 1] = c; 
    }
    fo(i , n) cout << a[i] << ' ';
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