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

string s[50];
int n , m;

void solve()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        s[i].clear();
        cin >> s[i];
    }
    bool mark[n][m];
    memset(mark , false , sizeof mark);
    for(int i = 0 ; i < n ; i++){
        if(s[i][0] == '1'){
            for(int j = 0 ; j < m ; j++){
                if(s[i][j] == '0'){
                    break;
                }
                mark[i][j] = true;
            }
        }
    }
    for(int j = 0 ; j < m ; j++){
        if(s[0][j] == '1'){
            for(int i = 0 ; i < n ; i++){
                if(s[i][j] == '0'){
                    break;
                }
                mark[i][j] = true;
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(s[i][j] == '1' && !mark[i][j]){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
