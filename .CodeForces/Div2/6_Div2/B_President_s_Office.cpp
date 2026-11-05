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
int n , m;
char c;
string s[101];
set<char> st;
bool mark[101][101];

void dfs(int i , int j){
    mark[i][j] = 1;
    if(s[i][j] != c){
        if(s[i][j] != '.'){
            st.insert(s[i][j]);
        }
        return;
    }
    if(i + 1 < n && !mark[i + 1][j]){
        dfs(i + 1 , j);
    }
    if(i - 1 >= 0 && !mark[i - 1][j]){
        dfs(i - 1 , j);
    }
    if(j + 1 < m && !mark[i][j + 1]){
        dfs(i , j + 1);
    }
    if(j - 1 >= 0 && !mark[i][j - 1]){
        dfs(i , j - 1);
    }
}
void solve()
{
    cin >> n >> m >> c;
    pii ind;
    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
        fo(j , m){
            if(s[i][j] == c){
                ind = {i , j};
            }
        }
    }
    dfs(ind.first , ind.second);
    cout << st.size() << ln;
}
int main(){
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
