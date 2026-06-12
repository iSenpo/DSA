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
    int q;
    cin >> q;
    vector<pair<int , int>> p(q);
    fo(i , q){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(all(p));
    int j = 0;
    int cnt = 0;
    vector<int> ans(q , 0);
    int flag = -1;
    fo(i , q){
        while(p[i].first >= a[j] && j < n){
            cnt++;
            j++;
            if(j == n){
                flag = i;
                break;
            }
        }
        if(flag != -1){
            break;
        }
        ans[i] = cnt;
    }
    if(flag != -1){
        for(int i = flag ; i < q ; i++){
            ans[i] = n;
        }
    }
    int res[q];
    fo(i , q){
        res[p[i].second] = ans[i];
    }
    fo(i , q){
        cout << res[i] << ln;
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