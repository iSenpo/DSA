#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'

int MOD = 1e9 + 7;
int n , m;
vector<vector<int>> dp;

int solve(int i , int j){
    //base:
    if(i >= n || j >= m){
        return 0;
    }
    if(i == n-1 && j == m-1){
        return 1;
    }
    //transition :
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    return dp[i][j] = (solve(i , j + 1) + solve(i + 1 , j))%MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    cin >> n >> m;
    char a[n][m];
    dp.resize(n + 1 , vector<int>(m + 1 , -1));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
            if(a[i][j] == '#'){
                dp[i][j] = 0;
            } 
        }
    }
    cout << solve(0 , 0);
    return 0;
}