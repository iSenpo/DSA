//example3 Max Sum Of Subsequence Non-Ajacent
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;

int a[N];
int dp[N];

int MaxSum(int i){
    //base!!!!!! :
    if(i == 0){
        if(a[i] < 0)
            dp[i] = 0;
        return dp[i] = a[0];
    }
    if(i == 1){
        if(a[i] < 0){
            
        }
            dp[i] = 0;
        return dp[i] = max(a[0] , a[1]);
    }
    //dp :
    if(dp[i] != 0){
        return dp[i];
    }
    
    return dp[i] = max(a[i]+MaxSum(i - 2) , MaxSum(i -1));
}
int main(){
    int n; 
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    memset(dp , 0 , sizeof(dp));
    cout << MaxSum( n-1 ) << endl;
    return 0;
}