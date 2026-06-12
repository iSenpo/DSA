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
    string s;
    cin >> s;
    vector<bool> l(n , false) , r(n , false);
    vector<int> lcnt(n , 0) , rcnt(n , 0);
    for(int i = 0 ; i < n ; i ++){
        if(!l[s[i] - 'a']){
            l[s[i] - 'a'] = true;
            lcnt[i] = 1;
        }
        if(!r[s[n - 1 - i] - 'a']){
            r[s[n - 1 - i] - 'a'] = true;
            rcnt[n - 1 - i] = 1;
        }
    }
    for(int i = 1 ; i < n ; i++){
        lcnt[i] = lcnt[i] + lcnt[i - 1];
    }
    for(int i = n - 2 ; i >= 0 ; i--){
        rcnt[i] = rcnt[i] + rcnt[i + 1];
    }
    int Max = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        Max = max(Max , lcnt[i] + rcnt[i + 1]);
    }
    cout << Max << ln;
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