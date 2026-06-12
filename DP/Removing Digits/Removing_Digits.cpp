#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e6 + 5;

vector<int> dp;

//Recursive Solution :
ll solve1(ll n){
    //base :
    if(n <= 0){
        return 0;
    }
    //transition :
    if(dp[n] != -1){
        return dp[n];
    }
    int temp = n;
    vector<int> t;
    while(temp != 0){
        t.push_back(temp%10);
        temp /= 10;
    }
    ll Min = N;
    for(int i = 0; i < t.size() ; i++){
        if(t[i] == 0){
            continue;
        }
        Min = min(Min ,solve1(n - t[i]));
    }
    return dp[n] = Min + 1;
}

//Iterative Solution :
ll solve2(ll n){
    //base :
    dp.resize(n + 1 , 0);
    dp[0] = 0;
    dp[1] = 1;
    //transition :
    for(int i = 1 ; i <= n ; i++){
        int temp = n;
        vector<int> t;
        while(temp != 0){
            t.push_back(temp%10);
            temp /= 10;
        }
        int Min = N;
        for(int i = 0; i < t.size() ; i++){
            if(t[i] == 0){
                continue;
            }
            if(t[i] <= n){
                Min = min(Min ,dp[n - t[i]]);
            }
        }
        dp[i] = Min + 1;
    }
    return dp[n];
}
int main(){
    int n;
    cin >> n;
    dp.resize(n + 1 , -1);
    cout << solve1(n) <<"  " <<solve2(n) -1;
    return 0;
}