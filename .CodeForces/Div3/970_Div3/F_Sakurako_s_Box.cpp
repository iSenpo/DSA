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
ll MOD = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 2e9 + 100;
const int MIN = -2e9 - 100;
// always check input!!!
ll pw(ll a, ll b)
{
    if (!b)
    {
        return 1;
    }
    ll temp = pw(a, b / 2);
    temp = (temp *temp) % MOD;
    if (b & 1)
    {
        temp *= a;
    }
    return temp % MOD;
}
ll d(ll a)
{
    return pw(a, MOD - 2);
}
void solve()
{
    ll n, p = 0;
    cin >> n;
    vector<ll> a(n), ps(n + 1);
    for (auto &&i : a)
    {
        cin >> i;
    }
    ps[0] = 0;
    for (ll i = 0; i < n; i++)
    {
        ps[i + 1] = ps[i] + a[i];
    }
    for (ll i = n - 1; i >= 1; i--)
    {
        p = (p + ((ps[i] * a[i]) % MOD)) % MOD;
    }
    cout << (p * (1LL) * d(n * (n - 1) / 2)) % MOD << ln;
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
