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
    int x , cnt1 = 0 , cnt2 = 0 , cnt3 = 0 , ans = 0;
    fo(i , n){
        cin >> x;
        if(x == 1) cnt1++;
        if(x == 2) cnt2++;
        if(x == 3) cnt3++;
        if(x == 4) ans++;
    }
    while(cnt3 > 0 && cnt1 > 0){
        ans++;
        cnt3--;
        cnt1--;
    }
    while(cnt3 > 0){
        cnt3--;
        ans++;
    }
    while(cnt2 > 0 && cnt1 > 0){
        ans++;
        cnt2--;
        cnt1-= 2;
    }
    while(cnt2 >= 2){
        cnt2 -= 2;
        ans++;
    }
    ans += cnt2;
    while(cnt1 >= 4){
        ans++;
        cnt1 -= 4;
    }
    if(cnt1 > 0) ans++;
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