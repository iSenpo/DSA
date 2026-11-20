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
    string s , t;
    cin >> s;
    cin >> t;
    vector<int> need(26 , 0) , cnt(26 , 0);
    string ans = "";
    int n = s.size();
    int m = t.size();
    fo(i , n) need[s[i] - 'a']++;
    fo(i , m) cnt[t[i] - 'a']++;
    int ptr = 0;
    int pts = 0;
    while(ptr < 26){
        if(need[ptr] > cnt[ptr]){
            cout << "Impossible\n";
            return;
        }
        while(pts < n && (s[pts] - 'a') <= ptr){
            ans += (char)(s[pts]);
            need[(s[pts] - 'a')]--;
            cnt[(s[pts] - 'a')]--;
            pts++;
        }
        ll d = cnt[ptr] - need[ptr];
        while(d--){
            ans += (char)('a' + ptr);
        }
        ptr++;
    }
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
