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
    int ns = sz(s) , nt = sz(t);
    int cnt = 0;
    int Max = 0;
    for(int i = 0 ; i < ns - nt + 1 ; i++){
        if(s.substr(i , nt) == t){
            int side = max(cnt , ns - nt - cnt);
            Max = max(Max , side);
        }
        cnt++;
    }
    for(int i = 1 ; i <= nt ; i++){
        string temp = s.substr(0 , nt - i) + s.substr(ns - i , i);
        if(temp == t){
            Max = max(Max , ns - nt);
        }
    }
    cout << Max << ln;
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