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

const int N  = 1e5 + 10;
//always check input!!!

int p[N];

void solve()
{
    int n , k;
    cin >> n >> k;
    vector<int> b(n) , ans(n);
    fo(i , n){
        b[i] = p[i];
    }
    int ptl = 0;
    int ptr = n - 1;
    fo(i , n){
        if((i + 1)%k == 0){
            ans[i] = b[ptl++];
        }
        else{
            ans[i] = b[ptr--];
        }
    }
    for(int i : ans){
        cout << i << ' ';
    }
    cout << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    cin >> t;
    iota(p , p + N , 1);
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow