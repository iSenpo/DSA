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
    int n;
    cin >> n;
    int a[n];
    fo(i , n) cin >> a[i];
    int ans[n];
    int x = 0;
    bool output = false;
    if(count(a , a + n , a[0]) == n){
        cout << 1 << ln;
        fo(i , n) cout << "1 ";
        cout << ln;
        return;
    }
    if(n%2 == 0){
        cout << 2 << ln;
        fo(i , n){
            cout << i%2 + 1 << ' ';
        }
        cout << ln;
        return;
    }
    else{
        for(int i = 0 ; i < n ; i++){
            if(a[i] == a[(i + 1)%n]){
                output = true;
                for(int j = i + 1 ; j < n ; j++){
                    ans[j] = x + 1;
                    x = 1 - x;
                }
                x = 0;
                for(int j = i ; j >= 0 ; j--){
                    ans[j] = x + 1;
                    x = 1 - x;
                }
                cout << 2 << ln;
                fo(i , n) cout << ans[i] << ' ';
                cout << ln;
                return;
            }
        }
    }
    if(!output){
        cout << 3 << ln;
        fo(i , n - 1){
            cout << i%2 + 1 << ' ';
        }
        cout << 3 << ln;
    }
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