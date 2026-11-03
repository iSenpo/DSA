#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)

const int N  = 2e5 + 10;
//always check input!!!
int memo[N];
int fib(int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 1;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    return memo[n] = fib(n - 1) + fib(n - 2);
}
void solve()
{
    int n;
    cin >> n;
    memset(memo , - 1, sizeof memo);
    cout << fib(n) << ln;
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