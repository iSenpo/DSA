#include <bits/stdc++.h>
using namespace std;

const int N  = 1e3 + 500;
vector<vector<int>> dp;


int main(){
    int n , m;
    cin >> n >> m;
    dp.resize(n + 1 , vector<int>(m + 1, N));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            else{
                //vertical
                for(int v = 0 ; v < i ; v++){
                    dp[i][j] = min(dp[i][j] , 1 + dp[v][j] + dp[i - v][j]);
                }
                //horizontal
                for(int h = 0 ; h < j ; h++){
                    dp[i][j] = min(dp[i][j] , 1 + dp[i][h] + dp[i][j - h]);
                }
            }
        }
    }
    cout << dp[n][m];
    return 0;
}