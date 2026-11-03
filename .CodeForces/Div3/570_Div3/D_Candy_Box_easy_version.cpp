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
    int a[n];
    map<int , int> cnt;
    vector<int> num;
    fo(i , n) {
        cin >> a[i];
        if(cnt[a[i]] == 0){
            num.pb(i);
        }
        cnt[a[i]]++;
    }
    ll ans = 0;
    vector<int> arr;
    fo(i , sz(num)){
        arr.push_back(cnt[a[num[i]]]);
    }
    sort(all(arr));
    reverse(all(arr));

    map<int , bool> mark;
    
    fo(i , sz(arr)){
        if(!mark[arr[i]]){
            ans += arr[i];
            mark[arr[i]] = 1;
            continue;
        }
        else{
            int k = 1;
            while(arr[i] - k > 0){
                if(!mark[arr[i] - k]){
                    ans += (arr[i] - k);
                    mark[arr[i] - k] = 1;
                    break;
                }
                k++;
            }
        }
    }
    cout << ans << ln;
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