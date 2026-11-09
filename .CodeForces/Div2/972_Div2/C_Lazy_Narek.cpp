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

string s = "narak";

void solve()
{
    ll n, m;
    pair<ll,ll> ans = {0,0};
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(5));
    for (ll i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (ll k = 0; k < 5; k++)
        {
            ll c = k;
            for (auto &&j : str)
            {
                if (j == s[c % 5])
                {
                    c++;
                }
            }
            a[i][k] = c;
        }
    }
    ll st = min(5ll, n);
    for (ll i = 0; i < (1ll << st); i++)
    {
        pair<ll,ll> tans = {0,0};
        for (ll mask = 1, j = 0; j < st; j++, mask *= 2)
        {
            if (mask & i)
            {
                tans.second += a[i][tans.second % 5];
            }
        }
        tans.first = tans.second / 5;
        ans = max(tans, ans);
    }
    if (n < 5)
    {
        cout << ans.first << "\n";
        return;
    }
    vector<pair<ll,ll>> dp(n + 1);
    dp[st] = ans;
    for (ll j = 5; j < n; j++)
    {
        for (ll k = 0; k < j; k++)
        {
            ans = dp[k];
            for (ll i = 0; i < (1ll << 5); i++)
            {
                ll tans = ans.second;
                for (ll mask = 1, x = 0; x < 5; x++, mask *= 2)
                {
                    if (mask & i)
                    {
                        tans += a[i][tans % 5];
                    }
                }
                ans.second = max(tans, ans.second);
            }
        }
    }
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
