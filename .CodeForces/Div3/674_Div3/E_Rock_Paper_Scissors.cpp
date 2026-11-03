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

const int N  = 2e9 + 10;
//always check input!!!

void solve()
{
    int n;
    cin >> n;
    int r1 , s1 , p1 , r2 ,s2, p2;
    cin >> r1 >> s1 >> p1 >> r2 >> s2 >> p2;
    ll best = 0;
    best += min(r1 , s2);
    best += min(s1 , p2);
    best += min(p1 , r2);
    int ans = N;
    if(r2 == s2 && r2 == p2){
        ans = 0;
    }
    else if(r2 >= s2 && r2 >= p2){
        ans = p1 - (p2 + s2);
    }
    else if(r2 <= s2 && s2 >= p2){
        ans =  r1 - (p2 + r2);
    }
    else if(p2 >= s2 && r2 <= p2){
        ans = s1 - (r2 + s2);
    }
    int r = min(r1 , p2);
    r1 -= r;
    p2 -= r;
    int s = min(s1 , r2);
    s1 -= s;
    r2 -= s;
    int p = min(p1 , s2);
    p1 -= p;
    s2 -= p;

    r = min(r1 , r2);
    r1 -= r;
    r2 -= r;
    s = min(s1 , s2);
    s1 -= s;
    s2 -= s;
    p = min(p1 , p2);
    p1 -= p;
    p2 -= p;
    ans = min(ans , r1 + s1 + p1);
    cout << ans << ' ' << best << ln; 
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