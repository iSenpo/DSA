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
const int INF = 1e9 + 100;
const int MIN = -2e9 - 100;
//always check input!!!

int f1(string s){
    int d1 = INF , d2 = INF;
    int n = sz(s);
    for(int i = n - 1 ; i >= 1 ; i--){
        if(s[i] == '0'){
            d1 = min(d1 , n - i - 1);
            for(int j = i - 1 ; j >= 1 ; j--){
                if(s[j] == '0'){
                    d2 = min(d2 , i - j - 1);
                    break;
                }
            }
            break;
        }
    }
    return d1 + d2;
}
int f2(string s){
    int d1 = INF , d2 = INF;
    int n = sz(s);
    for(int i = n - 1 ; i >= 1 ; i--){
        if(s[i] == '5'){
            d1 = min(d1 , n - i - 1);
            for(int j = i - 1 ; j >= 0 ; j--){
                if(s[j] == '2'){
                    d2 = min(d2 , i - j - 1);
                    //cerr << i << ' ' << j << ln;
                    break;
                }
            }
            break;
        }
    }
    return d1 + d2;
}
int f3(string s){
    int d1 = INF , d2 = INF;
    int n = sz(s);
    for(int i = n - 1 ; i >= 1 ; i--){
        if(s[i] == '0'){
            d1 = min(d1 , n - i - 1);
            for(int j = i - 1 ; j >= 0 ; j--){
                if(s[j] == '5'){
                    d2 = min(d2 , i - j - 1);
                    break;
                }
            }
            break;
        }
    }
    return d1 + d2;
}
int f4(string s){
    int d1 = INF , d2 = INF;
    int n = sz(s);
    for(int i = n - 1 ; i >= 1 ; i--){
        if(s[i] == '5'){
            d1 = min(d1 , n - i - 1);
            for(int j = i - 1 ; j >= 0 ; j--){
                if(s[j] == '7'){
                    d2 = min(d2 , i - j - 1);
                    break;
                }
            }
            break;
        }
    }
    return d1 + d2;
}
void solve()
{
    string s;
    cin >> s;
    cout << min({f1(s) , f2(s) , f3(s) , f4(s)}) << ln;
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
