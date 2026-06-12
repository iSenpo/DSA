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

const char r[3] = {'R' , 'G' , 'B'};
const char g[3] = {'B' , 'R' , 'G'};
const char b[3] = {'G' , 'B' , 'R'};

void solve()
{
    int n , k ;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n , 0) , b(n , 0) , c(n , 0);
    int ptr = 0;
    fo(i , n){
        if(s[i] != r[ptr]){
            a[i] = 1;
        }
        if(s[i] != g[ptr]){
            b[i] = 1;
        }
        if(s[i] != b[ptr]){
            c[i] = 1;
        }
        ptr++;
        if(ptr == 3){
            ptr = 0;
        }
    }
    vector<int> ps1(n + 1, 0) , ps2(n + 1, 0) , ps3(n + 1, 0);
    ps1[1] = a[0];
    ps2[1] = b[0];
    ps3[1] = c[0];
    for(int i = 1 ; i < n ; ++i){
        ps1[i + 1] = ps1[i] + a[i];
        ps2[i + 1] = ps2[i] + b[i];
        ps3[i + 1] = ps3[i] + c[i];
    }
    ll Min = N;
    for(int i = k ; i <= n ; ++i){
        Min = min<ll>(Min , ps1[i] - ps1[i - k]);
        Min = min<ll>(Min , ps2[i] - ps2[i - k]);
        Min = min<ll>(Min , ps3[i] - ps3[i - k]);
    }
    cout << Min << ln;
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