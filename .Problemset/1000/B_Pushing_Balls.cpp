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

const int N  = 55;
//always check input!!!
char a[N][N];
bool mark[N][N];
int n , m;
void dp(int i , int j){
    if(i > n || j > m){
        return;
    }
    mark[i][j] = true;
    if(!mark[i][j + 1] && a[i][j + 1] == '1'){
        dp(i , j + 1);
    }
    if(!mark[i + 1][j] && a[i + 1][j] == '1'){
        dp(i + 1 , j);
    }
}
void solve()
{
    cin >> n >> m;
    memset(mark , false , sizeof mark);
    fo(i , n){
        fo(j , m){
            cin >> a[i][j];
        }
    }
    fo(i , n){
        if(a[i][0] == '1' && !mark[i][0]){
            dp(i , 0);
        }
    }
    fo(i , m){
        if(a[0][i] == '1' && !mark[0][i]){
            dp(0 , i);
        }
    }
    fo(i , n){
        fo(j , m){
            if(a[i][j] == '1' && !mark[i][j]){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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