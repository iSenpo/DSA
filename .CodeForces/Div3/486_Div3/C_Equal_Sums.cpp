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
    int k = in();
    vector<vector<int>> a(k);
    vector<int> sum(k , 0);
    int cnt = 0;
    for(int i = 0 ; i < k ; ++i){
        int n;
        cin >> n;
        cnt += n;
        a[i].resize(n);
        for(int j = 0 ; j < n ; ++j){
            cin >> a[i][j];
            sum[i] += a[i][j];
        }
    }
    vector<tuple<int , int , int>> ans;
    int c = 0;
    for(int i = 0 ; i < k ; ++i){
        for(int j = 0 ; j < a[i].size() ; ++j){
            ans.pb(make_tuple(sum[i] - a[i][j] , i + 1 , j + 1));
        }
    }
    sort(all(ans));
    for(int i = 0 ; i < cnt - 1 ; ++i){
        if(get<0>(ans[i]) == get<0>(ans[i + 1]) && get<1>(ans[i]) != get<1>(ans[i + 1])){
            cout << "YES\n";
            cout << get<1>(ans[i]) << ' ' << get<2>(ans[i]) << ln;
            cout << get<1>(ans[i + 1]) << ' ' << get<2>(ans[i + 1]) << ln;
            return;
        }
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //t = in();
    while(t--){
        solve();
    }
    return 0;
}