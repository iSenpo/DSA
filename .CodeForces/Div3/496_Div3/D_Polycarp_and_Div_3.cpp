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
    string s;
    cin >> s;
    int ans = 0;
    int ctn1 = 0;
    int ctn2 = 0;
    int n;
    for(int i = 0 ; i < sz(s) ; ++i){
        int n = s[i] - '0';
        if(n%3 == 0){
            ans++;
            ctn1 = 0;
            ctn2 = 0;
            continue;
        }
        if(n%3 == 1){
            ctn1++;
        }
        if(n%3 == 2){
            ctn2++;
        }
        if(ctn1 == 3){
            ans++;
            ctn1 = 0;
            ctn2 = 0;
            continue;
        }
        if(ctn2 == 3){
            ans++;
            ctn1 = 0;
            ctn2 = 0;
            continue;
        }
        if(ctn1 && ctn2){
            ans++;
            ctn1 = 0;
            ctn2 = 0;
            continue;
        }
    }
    cout << ans << ln;
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