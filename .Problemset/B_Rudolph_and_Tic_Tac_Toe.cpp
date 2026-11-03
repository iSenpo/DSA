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

void solve()
{
    string s[3];
    fo(i , 3){
        cin >> s[i];
    }
    vector<bool> p(3 , false);
    int cnt = 0;
    for(char t : {'+' , 'O' , 'X'}){
        for(int i = 0 ; i < 3 ; i++){
            if(s[i][0] == t && s[i][1] == t && s[i][2] == t){
                p[cnt] = true;
            }
            if(s[0][i] == t && s[1][i] == t && s[2][i] == t){
                p[cnt] = true;
            }
        }
        if(s[0][0] == t && s[1][1] == t && s[2][2] == t){
            p[cnt] = true;
        }
        if(s[0][2] == t && s[1][1] == t && s[2][0] == t){
            p[cnt] = true;
        }
        cnt++;
    }
    if(p[0] && !p[1] && !p[2]){
        cout << "+\n";
    }
    else if(!p[0] && p[1] && !p[2]){
        cout << "O\n";
    }
    else if(!p[0] && !p[1] && p[2]){
        cout << "X\n";
    }
    else{
        cout << "DRAW\n";
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
