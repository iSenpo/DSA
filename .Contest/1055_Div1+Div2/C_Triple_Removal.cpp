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
    int q = in();
    int a[n] , zero[n + 1] , one[n + 1];
    zero[0] = one[0] = 0;
    fo(i , n){
        cin >> a[i];
        if(a[i] == 1){
            one[i]++;
        }
        else{
            zero[i]++;
        }
        zero[i + 1] = zero[i];
        one[i + 1] = one[i];
    }
    int dp[n + 1];
    memset(dp , 0 , sizeof dp);
    bool triple0 = false;
    bool triple1 = false;
    int cnt0 = 0 , cnt1 = 0;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //t = in();
    while(t--){
        solve();
    }
    return 0;
}