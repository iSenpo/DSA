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

vector<int> prim;
bool not_p[N + 10];

void solve()
{
    int n , k;
    cin >> n >> k;
    int a[n];
    int Max = 0;
    fo(i , n){
        cin >> a[i];
        Max = max(Max , a[i]);
    }
    int ans = 1;
    int ptr = 0;
    int d = prim[ptr];
    while(prim[ptr] <= Max){
        bool can = true;
        d = prim[ptr];
        int cnt = k;
        for(int i = 0 ; i < n ; i++){
            if(a[i] % d == 0){
                continue;
            }
            else{
                if(a[i] >= (d * 4) || a[i] == (d * 3)){
                    continue;
                }
                else if(cnt > 0){
                    cnt--;
                }
                else{
                    can = false;
                    break;
                }
            }
        }   
        if(can){
            ans = max(ans , d);
        }
        ptr++;
    }
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    for(int i = 2 ; i <= N ; i++){
        if(!not_p[i]){
            prim.push_back(i);
            for(int j = (i * 2) ; j <= N ; j += i){
                not_p[j] = true;
            }
        }
    }
    while(t--){
        solve();
    }
    return 0;
}
