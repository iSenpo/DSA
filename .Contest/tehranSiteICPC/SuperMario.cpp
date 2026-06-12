#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define mt(x , y , z) make_tuple(x , y , z)

// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 10007;


int n , m;
vector<vector<char>> a;

ll dp(int i, int j , int p){
    //base 
    if(a[i][j] == '#'){
        return 0;
    }
    //bot right
    if(i == n -1 && j == n -1){
        if(p == 2 || p == 0 || p == 4)
            return 1;
        return 0;
    }
    //top left
    if(i == 0 && j == 0){
        return dp(i + 1 , j , 2) + dp(i , j + 1 , 3);
    }
    //bot left
    if(i == n - 1 && j == 0){
        if(p == 3 || p == 5){
            return dp(i , j + 1 , 2);
        }
        else
            return 0;
    }
    //top right
    if(i == 0 && j == n - 1){
        if(p == 0 || p == 5){
            return dp(i + 1 , j , 4);
        }
        else
            return 0;
    }
    if(i == 0){
        if(p == 3 || p == 5){
            return dp(i + 1 , j , 3) + dp(i , j + 2 , 2);
        }
        else
            return 0;
    }
    if(i == n - 1){
        if(p == 0 || p == 2){
            return dp(i - 1 , j , 1) + dp(i , j + 1 , 0);
        }
        return 0;
    }
    if(j == 0){
        if(p == 0 || p == 5){
            return dp(i + 1 , j , 4) + dp(i , j + 1 , 0);
        }
        else{
            return 0;
        }
    }
    if(j == n - 1){
        if(p == 3 || p == 4){
            return dp(i , j - 1 , 1) + dp(i + 1 , j , 3);
        }
        else return 0;
    }
    if(p == 3){
        return dp(i , j - 1 , 1) + dp(i , j + 1 , 2) + dp(i + 1 , j , 3);
    }
    if(p == 0){
        return dp(i , j + 1 , 0) + dp(i + 1 , j , 1) + dp(i + 1 , j + 1 , 4);
    }
    if(p == 1){
        return dp(i , j - 1 , 0) + dp(i - 1 , j - 1 , 2) + dp(i + 1 , j - 1 , 5);
    }
    if(p == 2){
        return dp(i , j + 1 , 0) + dp(i + 1 , j + 1 , 4) + dp(i - 1 , j + 1 , 1);
    }
    if(p == 4){
        return dp(i + 1 , j , 3) + dp(i + 1 , j + 1 , 2) + dp(i + 1 , j - 1 , 1);
    }
    if(p == 5){
        return dp(i + 1 , j , 3) + dp(i + 1 , j + 1 , 2) + dp(i + 1 , j - 1 , 1);
    }
}
void solve()
{
    cin >> n >> m;
    a.resize(n , vector<char>(m));
    fo(i , n){
        fo(j , n){
            cin >> a[i][j];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow