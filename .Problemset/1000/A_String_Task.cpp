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
    int n = sz(s);
    string ans;
    fo(i , n){
        if(s[i] == 'A' || s[i] == 'a'){
        }
        else if(s[i] == 'O' || s[i] == 'o'){}
        else if(s[i] == 'Y' || s[i] == 'y'){}
        else if(s[i] == 'E' || s[i] == 'e'){}
        else if(s[i] == 'U' || s[i] == 'u'){}
        else if(s[i] == 'I' || s[i] == 'i'){}
        else{
            if(s[i] <= 90){
                s[i] += 32;
            }
            ans += ".";
            ans += s[i]; 
        }
    }
    cout << ans  << ln;
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