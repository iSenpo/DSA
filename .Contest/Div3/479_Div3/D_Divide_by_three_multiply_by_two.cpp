#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;

const ll N  = 200;

vector<ll> OUT[N];
vector<ll> IN[N];
vector<ll> a(N);

inline int in(){
    int x;
    cin >> x;
    return x;
}
void dfs(int v){
    cout << a[v] << ' ';
    if(!OUT[v].empty()){
        dfs(OUT[v][0]);
    }
}
void solve()
{
    int n = in();
    fo(i , n) cin >> a[i];
    fo(i , n){
        fo(j , n){
            if(i != j){
                if(a[i] * 2 == a[j]){
                    OUT[i].pb(j);
                    IN[j].pb(i);
                }
                if(a[i] * 3 == a[j]){
                    OUT[j].pb(i);
                    IN[i].pb(j);
                }
            }
        }
    }
    int start = 0;
    fo(i , n){
        if(IN[i].size() == 0){
            start = i;
        }
    }
    dfs(start);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //t = in();
    while(t--){
        solve();
    }
    return 0;
}