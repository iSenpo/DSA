#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; i++)
#define all(x) (x).begin(),(x).end()
int MOD = 1e9 + 7;
const int N  = 1e5 + 500;
int arr[N];

inline int in(){
    int x;
    cin >> x;
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int n = in();
    int m = in();
    int a[n] , b[m];
    fo(i ,n) cin >> a[i];
    fo(i , m) cin >> b[i];
    vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    vector<int> ans;
    int i = n , j = m;
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    cout << dp[n][m] << ln;
    for(int i = ans.size() -1 ; i >= 0 ; i--){
        cout << ans[i] << ' ';
    }
    return 0;
}