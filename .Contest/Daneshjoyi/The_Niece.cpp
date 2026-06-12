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
int MOD = 1e9 + 7;

const int N  = 2e5 + 10;
//always check input!!!
long long int v[19] ={(long long)8e18,(long long)8e17 ,(long long)8e16 , (long long)8e15,(long long)8e14 ,(long long)8e13 ,(long long) 8e12,(long long)8e11,(long long)8e10,(long long)8e9,(long long)8e8,(long long)8e7,(long long)8e6,(long long)8e5,(long long)8e4,(long long)8e3,(long long)8e2 , (long long)8e1 , (long long)8};
void solve()
{
    ll n;
    cin >> n;
    for(int i = 0 ; i < 20 ; i++){
        while(n > v[i] && n > 8){
            n -= v[i];
        }
    }
    if(n == 4 || n == 1){
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
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