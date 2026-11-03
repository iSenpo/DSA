#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ln '\n'
#define fo(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define set_dec(x) cout << fixed << setprecision(x);
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 2e9 + 100;
const int MIN = -2e9 - 100;
// always check input!!!

void solve()
{
    ll n, ans = LLONG_MAX;
    string s;
    cin >> n >> s;
    vector<ll> a(26, 0), b(26, 0), c(26, 0), d(26, 0);
    for (ll i = 0; i < n; i++)
    {
        if (i & 1)
        {
            b[s[i] - 'a']++;
        }
        else
        {
            a[s[i] - 'a']++;
        }
    }
    if (n & 1)
    {
        for (ll i = 0; i < n; i++)
        {
            if (i & 1)
            {
                b[s[i] - 'a']--;
                ll t = LLONG_MAX;
                for (ll i = 0; i < 26; i++)
                {
                    t = min(t, n / 2 - b[i] - c[i]);
                }
                ll t2 = LLONG_MAX;
                for (ll i = 0; i < 26; i++)
                {
                    t2 = min(t2, n / 2 - a[i] - d[i]);
                }
                ans = min(ans, t + t2);
                d[s[i] - 'a']++;
            }
            else
            {
                a[s[i] - 'a']--;
                ll t = LLONG_MAX;
                for (ll i = 0; i < 26; i++)
                {
                    t = min(t, n / 2 - b[i] - c[i]);
                }
                ll t2 = LLONG_MAX;
                for (ll i = 0; i < 26; i++)
                {
                    t2 = min(t2, n / 2 - a[i] - d[i]);
                }
                ans = min(ans, t + t2);
                c[s[i] - 'a']++;
            }
        }
        ans++;
    }
    else
    {
        ll t = LLONG_MAX;
        for (ll i = 0; i < 26; i++)
        {
            t = min(t, n / 2 - a[i]);
        }
        ans = t;
        t = LLONG_MAX;
        for (ll i = 0; i < 26; i++)
        {
            t = min(t, n / 2 - b[i]);
        }
        ans += t;
    }
    cout << ans << ln;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
