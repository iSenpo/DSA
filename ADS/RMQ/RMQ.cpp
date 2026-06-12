#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'

int n;
const int N = 2e5 + 10 , lg = 22 , INF = 1e9 + 10;
int dp[lg][N];
int a[N];
int get_ans(int l , int r){
    int ans = INF;
    int k = 0;
    while((1 << (k + 1) <= (r - l))){
        k++;
    }
    ans = min(dp[k][l] , dp[k][r - (1 << k)]);
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int q;
    cin >> n >> q;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        dp[0][i] = a[i];
    }
    for(int i = 1 ; i < lg ; i++){
        for(int j = 0 ; j + (1 << i) <= n ; j++){
            dp[i][j] = min(dp[i - 1][j] , dp[i - 1][j + (1 << (i - 1))]);
        }
    }
    while(q--){
        int l , r;
        cin >> l >> r;
        l--;
        cout << get_ans(l , r) << ln;
    }
    return 0;
}
