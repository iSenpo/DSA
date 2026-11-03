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
    int n;
    cin >> n;
    int a[n];
    fo(i , n) cin >> a[i];
    int cnt = 0;
    bool last = 0;
    for(int i = 0 ; i < n - 1; i++){
        if(a[i] > 0){
            continue;
        }
        else if(a[i] < 0 && a[i + 1] <= 0){
            i++;
        }
        else if(a[i] == 0 && a[i + 1] < 0){
            if(i == n - 2) last = 1;
            i++;
        }
        else if(a[i] == 0 && a[i + 1] > 0){
            continue;
        }
        else{
            cnt++;
        }
    }
    if(a[n - 1] < 0 && !last){
        cnt++;
    }
    cnt += count(a , a + n , 0);
    fo(i , n) a[i] = abs(a[i]);
    sort(a , a + n);
    ll sum = 0;
    for(int i = 0 ; i < cnt ; i++){
        sum += (-abs(a[i]));
    }
    for(int i = cnt ; i < n ;i++){
        sum += abs(a[i]);
    }
    cout << sum << ln;
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
