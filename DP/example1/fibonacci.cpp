#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e5 + 500;
ll dp[N];
int fib(int n){
    if(n == 1 || n == 2)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}
int main(){
    int n;
    cin >> n;
    memset(dp , -1 , sizeof(dp));
    cout << fib(n) ;
    return 0;
}