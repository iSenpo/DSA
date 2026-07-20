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

const int N  = 6 * 1000 + 700;
//always check input!!!

void solve()
{
    int n , k;
    cin >> n >> k;
    int a[n];
    vector<int> cnt(N , 0);
    fo(i , n){
        cin >> a[i];
        cnt[a[i]]++;
        if(cnt[a[i]] > k){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    vector<int> mark(N , 0);
    vector<int> ans(N + 10);
    fo(i , n){
        ans[i] = cnt[a[i]];
        mark[cnt[a[i]] - 1]++;
        cnt[a[i]]--;
    }
    int ptr = 0;
    fo(i , k){
        if(mark[i] == 0){
            while(mark[ans[ptr] - 1] == 1){
                ptr++;
            }
            mark[ans[ptr] - 1]--;
            mark[i]++;
            ans[ptr] = i + 1;
            ptr++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << ans[i] << ' ';
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