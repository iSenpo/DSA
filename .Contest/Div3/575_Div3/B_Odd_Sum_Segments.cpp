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

void solve()
{
    int n , k;
    cin >> n >> k;
    vector<int> odd , even;
    int x;
    fo(i , n){
        cin >> x;
        if(x % 2 == 0){
            even.push_back(i);
        }
        else{
            odd.push_back(i);
        }
    }
    if(odd.size() < k){
        cout << "NO\n";
        return;
    }
    if(odd.size() > k && ((odd.size()-k)%2 != 0)){
        cout << "NO\n";
        return;
    }
    int start = odd.size() - k;
    cout << "YES\n";
    for(int i = start ; i < odd.size() - 1 ; ++i){
        cout << odd[i] + 1 << ' ';
    }
    cout << n << ln;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
//check long long memory limit
//check int overflow