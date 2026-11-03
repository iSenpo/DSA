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
    int ans = 0;
    map<pii , unordered_set<int>> st , st2 , st3;
    set<pii> p1 , p2 , p3;
    for(int i = 1 ; i < n - 1 ; i++){
        st[{a[i] , a[i + 1]}].insert(a[i - 1]);
        st2[{a[i - 1], a[i]}].insert(a[i + 1]);
        st3[{a[i - 1] , a[i + 1]}].insert(a[i]);
        p1.insert({a[i] , a[i + 1]});
        p2.insert({a[i - 1] , a[i]});
        p3.insert({a[i - 1] , a[i + 1]});
    }
    for(int i = 0 ; i < sz(p1) ; i++){
        pii x = *p1.begin();
        p1.erase(p1.begin());
        int cnt = 0;
        while(!st[x].empty()){
            cnt++;
            st[x].erase(st[x].begin());
        }
        ans += cnt - 1;
    }
    for(int i = 0 ; i < sz(p2) ; i++){
        pii x = *p2.begin();
        p2.erase(p2.begin());
        int cnt = 0;
        while(!st2[x].empty()){
            cnt++;
            st2[x].erase(st2[x].begin());
        }
        ans += cnt - 1;
    }
    for(int i = 0 ; i < sz(p3) ; i++){
        pii x = *p3.begin();
        p3.erase(p3.begin());
        int cnt = 0;
        while(!st3[x].empty()){
            cnt++;
            st3[x].erase(st3[x].begin());
        }
        ans += cnt - 1;
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
