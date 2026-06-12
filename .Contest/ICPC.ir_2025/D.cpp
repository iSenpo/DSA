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
    int n ,m;
    bool h=1;
    cin >> n >> m;
    string a[n];
    int b[n][m];
    fo(i,n){
        cin >> a[i];
    }
    fo(i,n){
        fo(j,m){
            if((i+j) % 2 == 0){
                b[i][j] = 1;
            }else{
                b[i][j] = 2;
            
            }
            if(b[i][j] == 1 && a[i][j] == '1'){
                b[i][j] = 4;
            }
            if(b[i][j] == 2 && a[i][j] == '2'){
                b[i][j] = 3;
            }
            cout << b[i][j];
        }
        cout << endl;
    }
    
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