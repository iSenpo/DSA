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
    int n , k , s;
    cin >> n >> k >> s;
    if((n - 1)*k < s){
        cout << "NO\n";
        return;
    }
    if(k > s){
        cout << "NO\n";
        return;
    }
    int r = s%k;
    int d = s/k + 1;
    int dis = 0;
    cout << "YES\n";
    while(k--){
        if(r){
            cout << d + 1 << ' ';
            dis += d;
            r--;
        }
        else{
            cout << d << ' ';
            dis += d - 1;
        }
        if(k){
            if(s - dis < d){
                cout << d - dis + 2 << ' ';
            }
            else{
                cout << 1 << ' ';
            }
            k--;
        }
    }
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