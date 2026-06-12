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
    int r = 0 , l = 0 , u = 0 , d = 0;
    fo(i , n){
        if(s[i] == 'L'){
            l++;
        }
        if(s[i] == 'R'){
            r++;
        }
        if(s[i] == 'U'){
            u++;
        }
        if(s[i] == 'D'){
            d++;
        }
    }
    u = min(u , d);
    d = min(u , d);
    r = min(r , l);
    l = min(r , l);
    if((d == 0) && (r == 0)){
        cout << 0 << ln;
        return;
    }
    if(u == 0){
        cout << 2 << ln << "RL" << ln;
        return;
    }
    if(r == 0){
        cout << 2 << ln <<  "UD" << ln;
        return;
    }
    cout << u + r + d + l << ln;
    while(u--){
        cout << 'U';
    }
    while(r--){
        cout << 'R';
    }
    while(d--){
        cout << 'D';
    }
    while(l--){
        cout << 'L';
    }
    cout << ln;
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