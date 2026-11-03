#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

const int N  = 1e5 + 500;
int arr[N];

inline int in(){
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int n = in();
    int x1 , y1 , x2 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    if(x1 == x2){
        if(y1 > y2){
            cout << n - y1 + 1<< ln;
            return; 
        }
        else{
            cout << y1 + 1<< ln;
            return;
        }
    }
    if(y1 == y2){
        if(x1 > x2){
            cout << n - x1 + 1 << ln;
            return;
        }
        else{
            cout << x1 + 1<< ln;
            return;
        }
    }
    int wallx = x1;
    if(x1 > x2){
        wallx = n - x1;
    }
    int wally = y1;
    if(y1 > y2){
        wally = n - y1;
    }
    cout << max(wally + dy , wallx + dx) << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = in();
    while(t--){
        solve();
    }
    return 0;
}