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
    string s , t;
    cin >> s >> t;
    int cnt = 0;
    int ans = 0;
    for(int i = s.size() - 1 , j = t.size() - 1 ; i >= 0 , j >= 0 ; --i , --j){
        if(s[i] == t[j]){
            cnt++;
        }
        else{
            break;
        }
    }
    int cost1 = s.size() - cnt;
    int cost2 = t.size() - cnt;
    if(cost1 == 0 || cost2 == 0){
        cout << min(sz(s) + sz(t) , max(cost1 , cost2)) << ln;
    }
    else{
        cout << cost1 + cost2 << ln;
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