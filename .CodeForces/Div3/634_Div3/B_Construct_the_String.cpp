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

void solve()
{
    int n , a, b;
    cin >> n >> a >> b;
    string s = "";
    int k = b - 1;
    if(a == b){
        int i = 0;
        while(n > 0){
            s += ('a' + i);
            n--;
            i++;
            if(i == 26){
                i = 0;
            }
        }
        cout << s << ln;
        return;
    }
    int t = n;
    while(n > 0){
        for(int i = 0 ; i < (a - k) ; i++){
            s += 'a';
            n--;
        }
        for(int i = 0 ; i < k ; i++){
            s += ('b' + i);
            n--;
        }
    }
    s = s.substr(0 , t);
    cout << s << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow