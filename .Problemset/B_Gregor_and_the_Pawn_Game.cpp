#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;

const int N  = 1e5 + 500;
int arr[N];

inline int in(){
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int n = in();
    string a;
    string b;
    vector<bool> check(n , true);
    cin >> a >> b;
    int ans = 0;
    fo(i , n){
        if(b[i] == '0'){
            continue;
        }
        if(i > 0 && a[i - 1] == '1' && check[i - 1]){
            check[i -1] = false;
            ++ans;
        }
        else if(a[i] == '0'){
            check[i] = false;
            ++ans;
        }
        else if(i < n - 1 && a[i + 1] == '1' && check[i]){
            check[i + 1] = false;
            ++ans;
        }
    }
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = in();
    while(t--){
        solve();
    }
    return 0;
}