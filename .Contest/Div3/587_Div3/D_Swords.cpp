#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define mt(x , y , z) make_tuple(x , y , z)

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;

const int N  = 2e5 + 10;
//always check input!!!

inline int gcd(int a, int b) {
	while (a != 0 && b != 0) {
		if (a > b) {
			a %= b;
		} else {
			b %= a;
		}
	}
	return max(a, b);
}
void solve()
{
    int n;
    cin >> n;
    unordered_set<int> st;
    int a[n];
    int Max = 0;
    fo(i ,n){
        cin >> a[i];
        st.insert(a[i]);
        Max = max(a[i] , Max);
    }
    int cnt = count(a , a + n , Max);
    sort(a , a + n);
    if(sz(st) == 2){
        cout << n - cnt  << ' ' << a[n - 1] - a[0] << ln;
        return ;
    }
    //OK

    int x = Max - a[0];
    fo(i , n){
        x = gcd(x , Max - a[i]);
    }
    ll ans = 0;
    fo(i , n){
        ans += ((Max - a[i]) / x);
    }
    cout << ans << ' ' << x << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow