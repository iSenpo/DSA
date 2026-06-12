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
#define F first
#define S second
void solve()
{
    int n;
    cin >> n;
    string s[n];
    fo(i , n) cin >> s[i];
    vector<pii> a;
    fo(i , n){
        fo(j , n){
            if(s[i][j] == '*'){
                a.push_back({i , j});
            }
        }
    } 
    if(a[0].F != a[1].F && a[0].S != a[1].S){
        s[a[0].F][a[1].S] = '*';
        s[a[1].F][a[0].S] = '*';
    }
    else if(a[0].F == a[1].F){
        if(a[0].F > 0){
            s[0][a[0].S] = '*';
            s[0][a[1].S] = '*';
        }
        else{
            s[n - 1][a[0].S] = '*';
            s[n - 1][a[1].S] = '*';
        }
    }
    else if(a[0].S == a[1].S){
         if(a[0].S > 0){
            s[a[0].F][0] = '*';
            s[a[1].F][0] = '*';
        }
        else{
            s[a[0].F][n - 1] = '*';
            s[a[1].F][n - 1] = '*';
        }
    }
    fo(i , n){
        cout << s[i] << ln;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
