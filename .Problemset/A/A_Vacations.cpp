#include <bits/stdc++.h>
using namespace std;

const int N  = 1e9;
const int MAX = 1e5;
int a[MAX];
int dp[MAX][3];
int main(){
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    //base :
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == 3 || a[i] == 2){
            dp[i][1] = min(dp[i - 1][0] , dp[i - 1][2]);
        }
        else{
            dp[i][1] = N;
        }
        if(a[i] == 3 || a[i] == 1){
            dp[i][2] = min(dp[i-1][0] , dp[i-1][1]);
        }
        else{
            dp[i][2] = N;
        }
        dp[i][0] = 1 + min(dp[i-1][0] , min(dp[i-1][1] , dp[i-1][2]));
    }
    cout << min(dp[n][0] , min(dp[n][1] , dp[n][2])) ;
    return 0;
}