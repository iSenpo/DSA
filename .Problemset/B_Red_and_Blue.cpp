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
    int n;
    cin >> n;
    int a[n];
    fo(i , n) cin >> a[i];
    int Max1 = max(0 , a[0]);
    int sum = a[0];
    for(int i = 1; i < n ; i++){
        sum += a[i];
        Max1 = max(Max1 , sum);
    }
    int m;
    cin >> m;
    int b[m];
    fo(i , m) cin >> b[i];
    int Max2 = max(0 , b[0]) , sum2 = b[0];
    for(int i = 1 ; i < m ; i++){
        sum2 += b[i];
        Max2 = max(Max2 , sum2);
    }
    cout << Max1 + Max2 << ln;
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