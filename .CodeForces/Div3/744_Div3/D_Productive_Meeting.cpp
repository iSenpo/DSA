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
    vector<pii> a(n) , ans;
    ll sum = 0;
    fo(i , n) {
        cin >> a[i].first;
        a[i].second = i + 1;
        sum += a[i].first;
    }
    sort(all(a));
    ll d = sum/2;
    int ptr = n - 1;
    while(d > a[ptr].first){
        d -= a[ptr].first;
        ptr--;
    }
    int ptl = 0;
    while(d-- && a[ptr].first > 0){
       if(a[ptl].first == 0){
            ptl++;
            continue;
        }
        if(ptl == ptr){
            break;
        }
        ans.push_back({a[ptl].second , a[ptr].second});
        a[ptr].first--;
        a[ptl].first--;
    }
    ptr = n - 1;
    while(ptl < ptr){
        if(a[ptl].first == 0){
            ptl++;
            continue;
        }
        if(a[ptr].first == 0){
            ptr--;
            continue;
        }
        ans.push_back({a[ptl].second , a[ptr].second});
        a[ptr].first--;
        a[ptl].first--;
    }
    cout << ans.size() << ln;
    for(auto i : ans){
        cout << i.first << ' ' << i.second << ln;
    }
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
