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
    int n;
    cin >> n;
    vector<int> a(n);
    fo(i , n) cin >> a[i];
    sort(all(a));
    deque<int> q;
    bool boli = true;
    for(int i = 0 ; i < n; i++){
        if(i%2){
            q.push_front(a[i]);
        }
        else{
            q.push_back(a[i]);
        }
    }
    vector<int> v(all(q));
    int Max = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        Max = max(abs(v[i + 1] - v[i]) , Max);
    }
    Max = max(Max , abs(v[0] - v[n - 1]));
    cout << Max << ln;
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