#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for(int i = 0 ; i < n ; i++)
int MOD = 1e9 + 7;
const int N  = 2e9;


int arr[] = {1,5,10,20,100} , m = 5;

int solve(int n)
{   
    //base :
    vector<int> dp(n + 1, N);
    dp[0] = 0;

    //transition :
    for(ll i = 1 ; i <= n; i++){

        for(int j = 0 ; j < m ; j++)
        {
            if(arr[j] <= i)
            {
                ll subRes = dp[i - arr[j]];

                if(subRes != N && subRes + 1 < dp[i])
                {
                    dp[i] = subRes + 1;
                }
            }
        }
    }
    return dp[n];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}