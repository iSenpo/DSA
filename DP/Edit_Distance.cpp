#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
const int N = 1e6;

vector<vector<int>> dp;
int n , m;

void solve(string s , string t){
    //base :
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = i;
    }
    for(int i = 0 ; i <= m ; i++){
        dp[0][i] = i;
    }
    //transition:
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = dp[i - 1][j - 1] + 1;
                dp[i][j] = min(dp[i][j] , dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j] , dp[i][j - 1] + 1);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    string s , t;
    cin >> s >> t;
    n = s.size();
    m = t.size();
    dp.resize(n + 5 , vector<int>(m + 5 , N));
    solve(s , t);
    cout << dp[n][m] << ln;
    return 0;
}