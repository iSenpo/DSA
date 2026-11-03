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
    vector<int> a(n + 2 , INF) , l(n + 2 , INF) , r(n + 2 , INF);
    fo(i , n) cin >> a[i + 1];
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == 0){
            l[i] = i;
        }
        else{
            l[i] = l[i - 1];
        }
    }
    for(int i = n ; i >= 1 ; i--){
        if(a[i] == 0){
            r[i] = i;
        }
        else{
            r[i] = r[i + 1];
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == -1 || a[i] == 0){
            continue;
        }
        if(abs(i - l[i - 1]) < a[i] || abs(i - r[i + 1]) < a[i]){
            cout << - 1 << ln;
            return;
        }
        bool left = false , right = false;
        if(i - a[i] >= 1 && a[i - a[i]] == -1){
            left = 1;
        }
        if(i + a[i] <= n && a[i + a[i]] == -1){
            right = 1;
        }
        if(left && right){
            continue;
        }
        else if(left){
            a[i - a[i]] = 0;
        }
        else if(right){
            a[i + a[i]] = 0;
        }
        else{
            cout << - 1 << ln;
            return;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == 0){
            l[i] = i;
        }
        else{
            l[i] = l[i - 1];
        }
    }
    for(int i = n ; i >= 1 ; i--){
        if(a[i] == 0){
            r[i] = i;
        }
        else{
            r[i] = r[i + 1];
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == -1 || a[i] == 0){
            continue;
        }
        if(abs(i - l[i - 1]) < a[i] || abs(i - r[i + 1]) < a[i]){
            cout << - 1 << ln;
            return;
        }
        bool left = false , right = false;
        if(i - a[i] >= 1 && a[i - a[i]] == -1){
            left = 1;
        }
        if(i + a[i] <= n && a[i + a[i]] == -1){
            right = 1;
        }
        if(left && right){
            a[i - a[i]] = 0;
        }
        else if(left){
            a[i - a[i]] = 0;
        }
        else if(right){
            a[i + a[i]] = 0;
        }
        else{
            cout << - 1 << ln;
            return;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == 0){
            l[i] = i;
        }
        else{
            l[i] = l[i - 1];
        }
    }
    for(int i = n ; i >= 1 ; i--){
        if(a[i] == 0){
            r[i] = i;
        }
        else{
            r[i] = r[i + 1];
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == -1){
            a[i] = min(abs(l[i - 1] - i) , abs(r[i + 1] - i));
        }
    }
    for(int i : a){
        if(i == 0) cout << 1;
        else cout << 0;
    }
    cout << ln;
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
