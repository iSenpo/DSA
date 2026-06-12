#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;
int n , x;
vector<int> h , s;
vector<vector<int>> dp;

//Recursive Solution :
int solve1(int x,int i){
    //base :
    if(i <= 0 || x <= 0){
        return 0;
    }
    //transition :
    if(dp[x][i] != -1){
        return dp[x][i];
    }
    int skip = solve1(x , i-1);
    int pick = 0;
    if(x - h[i] >= 0){
       pick = s[i] + solve1(x - h[i] , i -1);
    }
    dp[x][i] = max(skip , pick);
    return dp[x][i];
}

//Iterative Solution :
int solve2(){
    //base :

    //transition :
    dp.resize(x + 1 , vector<int>(n + 1 ,0));
    for(int i = 1; i <= x ; i++){
        for(int j = 1; j <= n ; j++){
            int pick = 0;
            int skip = dp[i][j-1];
            if(i >= h[j]){
                pick = s[j] + dp[i - h[j]][j-1];
            }
            dp[i][j] = max(pick , skip);
        }
    }
    return dp[x][n];
}
int main(){
    cin >> n >> x;
    h.resize(n + 1);
    s.resize(n + 1);
    dp.resize(x + 1 , vector<int>(n + 1 ,-1));
    for(int i = 1; i <= n ; i++){
        cin >> h[i];
    }
    for(int i = 1; i <= n ; i++){
        cin >> s[i];
    }
    for(int i = 0; i <= x ; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= n ; i++){
        dp[0][i] = 0;
    }
    cout << solve2() << " " << solve1(x , n);
    return 0;
}