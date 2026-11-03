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

const int N  = 120 * 1000 + 10;
//always check input!!!
int a[N];
int n;
int last;
map<int , int> cnt;

bool check(int x){
    for(int i = 0 ; i < 31 ; ++i){
        int j = 1 << i;
        int d = j - x;
        if(d == x && cnt[x] < 2){
            continue;
        }
        if(binary_search(a , a + n , d)){
            last = d;
            return true;
        }
    }
    return false;
}
void solve()
{
    cin >> n;
    if(n == 0){
        cout << 0;
        return;
    }
    fo(i , n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a , a + n);
    int ans = 0;
    map<int , bool> dp;
    
    for(int i = 0 ; i < n ; ++i){
        if(dp[a[i]]){
            continue;
        }
        if(check(a[i])){
            if(last == a[i]){
                if(cnt[a[i]] > 1){
                    dp[a[i]] = true;
                }
                else{
                    ans++;
                }
            }
            else{
                dp[a[i]] = true;
                dp[last] = true;
            }
        }
        else{
            ans++;
        }
    }
    cout << ans << ln;
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