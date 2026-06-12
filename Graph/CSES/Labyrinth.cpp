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

vector<vector<char>> a;
vector<vector<bool>> mark;
vector<pii> ans;
int n , m;
bool path = false;
bool isOk(int i , int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;
    }
    if(a[i][j] == '#'){
        return false;
    }
    if(mark[i][j]){
        return false;
    }
    return true;
}
void dfs(int i , int j){
    if(a[i][j] == 'B'){
        path = true;
        ans.push_back({i , j});
        return;
    }
    if(path){
        ans.push_back({i , j});
        return;
    }
    for(int k = 0 ; k < 4 ; k++){
        if(isOk(i + dx[k] , j + dy[k])){
            dfs(i + dx[k] , j + dy[k]);
        }
    }
}
void solve()
{
    cin >> n >> m;
    a.resize(n ,vector<char>(m));
    mark.resize(n ,vector<bool>(m , false));
    int start[2];
    fo(i , n){
        fo(j , m){
            cin >> a[i][j];
            if(a[i][j] == 'A'){
                start[0] = i;
                start[1] = j;
            }
        }
    }
    dfs(start[0] , start[1]);
    reverse(all(ans));
    if(!path){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    string p = "";
    for(int i = 1 ; i < ans.size() ; i++){
        int px = ans[i - 1].first , py = ans[i - 1].second;
        int x = ans[i].first , y = ans[i].second;
        if(y < py){
            p += 'L';
        }
        else if(y > py){
            p += 'R';
        }
        else if(x > px){
            p += 'D';
        }
        else if(x < px){
            p += 'U';
        }
    }
    cout << p.size() << ln << p << ln;
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
