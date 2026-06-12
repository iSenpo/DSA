//https://cses.fi/problemset/task/1634
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e6 + 500;

int Maxx = 2e9;
int n;
vector<int> dp(N,N);
int a[N];

//Recursive Solution :
int solve1(int i){
    //base :
    if(i == 0){
        return 0;
    }
    if(i < 0){
        return Maxx;
    }
    //transition :
    if(dp[i] != N){
        return dp[i];
    }
    int res = Maxx;
    for(int j = 0; j < n ; j++){
        res = min( res , solve1(i - a[j]) + 1 );
    }
    return dp[i] = res;
} 

//Iterative Solution :
int solve2(int x){
    //base :
    dp[0] = 0;

    //transition :
    for(int i = 0; i <= x ; i++){
        for(int j = 0; j < n; j++){
            if(a[j] <= i){
                dp[i] = min(dp[i] , dp[i - a[j]] + 1);
            }
        }
    }
    return dp[x];
}
int main(){
    int x;
    cin >> n >> x;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    int ans = solve1(x);
    if(ans == Maxx){
        cout << -1 ;
    }
    else{
        cout << solve1(x) << endl << solve2(x);
    }
    return 0;
}