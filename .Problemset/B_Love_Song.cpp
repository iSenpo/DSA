#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
#define all(x) (x).begin(),(x).end()
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];
vector<int> dp;
int in(){
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int l = in();
    int r = in();
    if(l == 0){
        cout << dp[r] << ln ;
        return;
    }
    cout << dp[r] - dp[l-1] << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n = in(); 
    int q = in();
    string s;
    cin >> s;
    dp.resize(n + 1 , 0);
    dp[0] = s[0] - 'a' + 1;
    for(int i = 0 ; i < n ; i++){
        int k = s[i] - 'a' + 1;
        dp[i + 1] = k + dp[i];
    }
    while(q--){
        solve();
    }
    return 0;
}