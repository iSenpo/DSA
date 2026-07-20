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
    int x;
    int cnt0 = 0 , cnt1 = 0 , cnt2 = 0;
    int a[n];
    fo(i , n){
        cin >> x;
        a[i] = x;
        if(x%3 == 0)
            cnt0++;
        else if(x%3 == 1)
            cnt1++;
        else 
            cnt2++;
    }
    ll ans = 0;
    int d = n / 3;
    fo(i , n){
        if(a[i]%3 == 2 && cnt0 < d && cnt2 > d){
            a[i]++;
            cnt0++;
            cnt2--;
            ans++;
        }
        else if(a[i]%3 == 0 && cnt1 < d && cnt0 > d){
            a[i]++;
            cnt1++;
            cnt0--;
            ans++;
        }
        else if(a[i]%3 == 1 && cnt2 < d && cnt1 > d){
            a[i]++;
            cnt2++;
            cnt1--;
            ans++;
        }
    }
    fo(i , n){
        if(a[i]%3 == 1 && cnt0 < d && cnt1 > d){
            a[i] += 2;
            cnt0++;
            cnt1--;
            ans += 2;
        }
        else if(a[i]%3 == 2 && cnt1 < d && cnt2 > d){
            a[i] += 2;
            cnt1++;
            cnt2--;
            ans += 2;
        }
        else if(a[i]%3 == 0 && cnt2 < d && cnt0 > d){
            a[i] += 2;
            cnt2++;
            cnt0--;
            ans += 2;
        }
    }
    //cerr << cnt0 << ' ' << cnt1 << ' ' << cnt2 << ln;
    cout << ans << ln;
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
