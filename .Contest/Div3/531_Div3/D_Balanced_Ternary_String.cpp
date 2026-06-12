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
    string s;
    cin >> s;
    int d = n/3;
    int cnt0 = 0 , cnt1 = 0 , cnt2 = 0;
    fo(i , n){
        if(s[i] == '0'){
            cnt0++;
        }
        else if(s[i] == '1'){
            cnt1++;
        }
        else if(s[i] == '2'){
            cnt2++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '1' && cnt0 < d && cnt1 > d){
            s[i] = '0';
            cnt0++;
            cnt1--;
        }
        else if(s[i] == '2' && cnt0 < d && cnt2 > d){
            s[i] = '0';
            cnt0++;
            cnt2--;
        }
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        if(s[i] == '0' && cnt2 < d && cnt0 > d){
            s[i] = '2';
            cnt2++;
            cnt0--;
        }
        else if(s[i] == '1' && cnt2 < d && cnt1 > d){
            s[i] = '2';
            cnt2++;
            cnt1--;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '2' && cnt1 < d && cnt2 > d){
            s[i] = '1';
            cnt1++;
            cnt2--;
        }
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        if(s[i] == '0' && cnt0 > d && cnt1 < d){
            s[i] = '1';
            cnt1++;
            cnt0--;
        }
    }
    cout << s << ln;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
