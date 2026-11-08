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
const ll INF = 2e18 + 100;
const int MIN = -2e9 - 100;
//always check input!!!


void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), d(n - 1);
    fo(i , n) cin >> a[i];
    ll maxx = 0 , ans = INF;
    vector<int> twoc;

    for(int i = 0; i < n - 1; i++){
        d[i] = abs(a[i + 1] - a[i]);
        maxx = max(maxx, d[i]);
    }
    ans = maxx;
    for(int i = 0; i < n - 1; i++){
        if(d[i] == maxx){
            twoc.pb(i);
        }
    }

    if(twoc.size() > 2){
        cout << ans << ln;
        return;
    }

    vector<ll> pref(n - 1), suff(n - 1);

    for(int i = 0; i < n - 1; i++){
        pref[i] = max(d[i], i ? pref[i - 1] : 0LL);
    }

    for (int i = n - 2; i >= 0; i--) {
        suff[i] = max(d[i], i < n - 2 ? suff[i + 1] : 0LL);
    }

    auto leftMax = [&](int i) -> ll {
        return i < 0 ? 0LL : pref[i];
    };

    auto rightMax = [&](int i) -> ll {
        return i >= n - 1 ? 0LL : suff[i];
    };

    if (twoc.size() == 2) {

        int l = twoc[0] + 1;
        int r = twoc[1];

        ll inside = 0;

        for (int i = l; i < r; i++)
            inside = max(inside, 2 * d[i]);

        ll curr = max({
            leftMax(l - 2),
            rightMax(r + 1),
            inside
        });

        if (l > 0)
            curr = max(curr, abs(a[l - 1] - 2 * a[r]));

        if (r < n - 1)
            curr = max(curr, abs(2 * a[l] - a[r + 1]));

        cout << min(ans, curr) << ln;
        return;
    }

    int i = twoc[0];

    ll inside = 0;

    for (int l = i; l >= 0; l--) {

        ll curr = max({
            leftMax(l - 2),
            rightMax(i + 1),
            2 * inside
        });

        if (l > 0)
            curr = max(curr, abs(a[l - 1] - 2 * a[i]));

        curr = max(curr, abs(2 * a[l] - a[i + 1]));

        ans = min(ans, curr);

        if (l > 0)
            inside = max(inside, d[l - 1]);
    }

    inside = 0;

    for (int r = i + 1; r < n; r++) {

        ll curr = max({
            leftMax(i - 1),
            rightMax(r + 1),
            2 * inside
        });

        curr = max(curr, abs(a[i] - 2 * a[r]));

        if (r < n - 1)
            curr = max(curr, abs(2 * a[i + 1] - a[r + 1]));

        ans = min(ans, curr);

        if (r < n - 1)
            inside = max(inside, d[r]);
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
