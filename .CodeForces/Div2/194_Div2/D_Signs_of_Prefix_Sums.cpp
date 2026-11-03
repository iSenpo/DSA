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
    ll n;
    string s;
    cin >> n >> s;
    vector<vector<char>> v(1);
    v.back().push_back('0');
    for (ll i = 0; i < n; i++)
    {
        if (v.back().back() == s[i])
        {
            v.back().push_back(s[i]);
        }
        else
        {
            v.push_back({s[i]});
        }
    }
    for (ll i = 0; i < v.size(); i++)
    {
        if (v[i].back() == '0' && v[i].size() > 1)
        {
            cout << "-1\n";
            return;
        }
    }
    for (ll i = 1; i < v.size() - 1; i++)
    {
        if (v[i].size() % 2 == 0 && (v[i - 1].back() == '-' || v[i - 1].back() == '+') && (v[i + 1].back() == '-' || v[i + 1].back() == '+'))
        {
            cout << "3\n";
            return;
        }
    }
    for (ll i = 1; i < v.size() - 1; i++)
    {
        if (v[i].back() == '0')
        {
            continue;
        }
        if (v[i + 1].back() == '0' && v[i - 1].back() == '0' && v[i].size() % 2)
        {
            continue;
        }
        cout << "2\n";
        return;
    }
    cout << "1\n";
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
