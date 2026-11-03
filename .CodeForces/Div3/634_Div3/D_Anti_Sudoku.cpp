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
    string s[9];
    fo(i , 9) cin >> s[i];
    if(s[0][0] == '9'){
        s[0][0] = '1';
    }
    else{
        s[0][0]++;
    }
    if(s[1][3] == '9'){
        s[1][3] = '1';
    }
    else{
        s[1][3]++;
    }
    if(s[2][6] == '9'){
        s[2][6] = '1';
    }
    else{
        s[2][6]++;
    }
    if(s[3][1] == '9'){
        s[3][1] = '1';
    }
    else{
        s[3][1]++;
    }
    if(s[4][4] == '9'){
        s[4][4] = '1';
    }
    else{
        s[4][4]++;
    }
    if(s[5][7] == '9'){
        s[5][7] = '1';
    }
    else{
        s[5][7]++;
    }
    if(s[6][2] == '9'){
        s[6][2] = '1';
    }
    else{
        s[6][2]++;
    }
    if(s[7][5] == '9'){
        s[7][5] = '1';
    }
    else{
        s[7][5]++;
    }
    if(s[8][8] == '9'){
        s[8][8] = '1';
    }
    else{
        s[8][8]++;
    }
    fo(i , 9){
        cout << s[i] << ln;
    }
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