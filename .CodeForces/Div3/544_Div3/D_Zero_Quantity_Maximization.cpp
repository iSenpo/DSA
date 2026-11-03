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

int gcd(int a , int b){
    while(b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}
void solve()
{
    int n;
    cin >> n;
    int a[n] , b[n];
    fo(i , n) cin >> a[i];
    fo(i , n) cin >> b[i];
    map<pii, int> cnt;
    int Max = 0;
    int cnt0 = 0;
    fo(i , n){
        if(a[i] < 0){
            a[i] = -a[i];
            b[i] = -b[i];
        }
        if(a[i] == 0){
            if(b[i] == 0)
                cnt0++;
            continue;
        }
        int g = gcd(abs(a[i]) , abs(b[i]));
        b[i] /= g;
        a[i] /= g;
        cnt[{b[i] , a[i]}]++;
        Max = max(Max , cnt[{b[i] , a[i]}]);
    }
    Max += cnt0;
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