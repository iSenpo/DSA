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
    int n;
    cin >> n;
    int k = n/6;
    vector<int> a(n);
    fo(i , n) cin >> a[i];
    map<int , int> ptr;
    ll ans = 0;
    ptr[4] = 0;
    ptr[8] = 0;
    ptr[15] = 0;
    ptr[16] = 0;
    ptr[23] = 0;
    ptr[42] = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == 4){
            ptr[a[i]]++;
        }
        else if(a[i] == 8){
            if(ptr[4] > ptr[8]){
                ptr[8]++;
            }
            else{
                ans++;
            }
        }
        else if(a[i] == 15){
            if(ptr[8] > ptr[15]){
                ptr[15]++;
            }
            else{
                ans++;
            }
        }
        else if(a[i] == 16){
            if(ptr[15] > ptr[16]){
                ptr[16]++;
            }
            else{
                ans++;
            }
        }
        else if(a[i] == 23){
            if(ptr[16] > ptr[23]){
                ptr[23]++;
            }
            else{
                ans++;
            }
        }
        else if(a[i] == 42){
            if(ptr[23] > ptr[42]){
                ptr[42]++;
            }
            else{
                ans++;
            }
        }
        else{
            ans++;
        }
    }
    ans += abs(ptr[4] - ptr[42]);
    ans += abs(ptr[8] - ptr[42]);
    ans += abs(ptr[15] - ptr[42]);
    ans += abs(ptr[16] - ptr[42]);
    ans += abs(ptr[23] - ptr[42]);
    
    cout << ans << ln;
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