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
const int INF = 2e18 + 100;
const int MIN = -2e9 - 100;
// always check input!!!

// void bkt(ll x , ll y , ll cost , int i){
//     if(x == y){
//         ans = min(cost , ans);
//         return;
//     }
//     if(x < y){
//         swap(x , y);
//     }
//     ll j = (1 << i);
//     if(j > x) return;
//     bkt(x / j , y , cost + j , i + 1);
//     bkt(x , y , cost , i + 1);
// }
void solve()
{
    ll x, y;
    cin >> x >> y;
    ll t1 = x, t2 = y, ans = 0;
    string s1 = "", s2 = "";
    /*for (int i = 0 ; i <= 60 ; i++)
    {
        ll j = 1LL << i;
        if (t1 / j > 0)
        {
            s1 += "1";
            t1 /= j;
        }
        else
        {
            s1 += "0";
        }
        if(t1 == 0) break;
    }
    for (int i = 0 ; i <= 60 ; i++)
    {
        ll j = 1ll << i;
        if(t2 / j > 0)
        {
            s2 += "1";
            t2 /= j;
        }
        else
        {
            s2 += "0";
        }
        if(t2 == 0) break;
    }
    */
    while (x > 0)
    {
        s1.push_back('0' + (x & 1));
        x /= 2;
    }
    while (y > 0)
    {
        s2.push_back('0' + (y & 1));
        y /= 2;
    }
    /*reverse(all(s1));
    reverse(all(s2));*/
    while (s1.size() && s2.size() && s1.back() == s2.back())
    {
        s1.pop_back();
        s2.pop_back();
    }
    /*while (s1.size() && s1.back() == '0')
    {
        s1.pop_back();
    }
    while (s2.size() && s2.back() == '0')
    {
        s2.pop_back();
    }*/
    if (s1.size() == 2 && s2.size() == 2)
    {
        cout << "14\n";
        return;
    }
    if (s1.size() == 1 && s2.size() == 1)
    {
        cout << "12\n";
        return;
    }
    
    ll sum = s1.size() + s2.size();
    vector<ll> a(61);
    a[0] = 1;
    for (ll i = 1; i < 61; i++)
    {
        a[i] = a[i - 1] + i + 1;
    }
    while (sum)
    {
        ll p = lower_bound(all(a), sum) - a.begin() + 1;
        ans += (1ll << p);
        sum -= p;
    }
    cout << ans << "\n";
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
