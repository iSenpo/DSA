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
    int a , b;
    cin >> a >> b;
    int n = a + b;
    string s;
    cin >> s;
    fo(i , n){
        if(s[i] == '0')
            a--;
        else if(s[i] == '1')
            b--;
    }
    for(int i = 0 ; i < n/2 ; i++){
        if(s[i] == '?' && s[n - 1 - i] == '0'){
            if(a < 0){
                cout << -1 << ln ;
                return;
            }
            else{
                s[i] = '0';
                a--;
            }
        }
        else if(s[i] == '?' && s[n - 1 - i] == '1'){
            if(b < 0){
                cout << -1 << ln ;
                return;
            }
            else{
                s[i] = '1';
                b--;
            }
        }
        else if(s[i] == '0' && s[n - 1 - i] == '?'){
            if(a < 0){
                cout << -1 << ln ;
                return;
            }
            else{
                s[n - 1 - i] = '0';
                a--;
            }
        }
        else if(s[i] == '1' && s[n - 1 - i] == '?'){
            if(b < 0){
                cout << -1 << ln ;
                return;
            }
            else{
                s[n - 1 - i] = '1';
                b--;
            }
        }
    }
    for(int i = 0 ; i < n/2 ; i++){
        if(s[i] == '?' && s[n - 1 - i] == '?'){
            if(a >= 2){
                s[i] = '0';
                s[n - 1 - i] = '0';
                a -= 2;
            }
            else if(b >= 2){
                s[i] = '1';
                s[n - 1 - i] = '1';
                b -= 2;
            }
            else{
                cout << -1 << ln ;
                return;
            }
        }
    }
    if(n%2 == 1 && s[n/2] == '?'){
        if(a > 0){
            s[n/2] = '0';
            a--;
        }
        else if(b > 0){
            s[n/2] = '1';
            b--;
        }
        else{
            cout << -1 << ln;
            return;
        }
    }
    if(a > 0 || b > 0){
        cout << -1 << ln;
        return;
    }
    for(int i = 0 ; i < n/2 ; i++){
        if(s[i] != s[n - 1 - i]){
            cout << -1 << ln;
            return;
        }
    }
    cout << s << ln;
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
