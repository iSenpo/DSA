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
    int n , m;
    cin >> n >> m;
    vector<int> a(n) , p(m);
    fo(i , n) cin >> a[i];
    fo(i , m) cin >> p[i];
    vector<int> ans;
    vector<int> t(all(a));
    sort(all(t));
    if(t == a){
        cout << "YES\n";
        return;
    }
    int k = n - 1;
    while(k--){
        bool swaps = true;
        fo(i , n - 1){
            if(a[i] > a[i + 1]){
                swap(a[i] , a[i + 1]);
                ans.pb(i + 1);
                swaps = false;
            }
        }
        if(swaps){
            break;
        }
    }
    if(t != a){
        cout << "NO\n";
        return;
    }
    sort(all(p));
    sort(all(ans));
    bool check = true;
    for(int i : ans){
        check = false;
        fo(j , m){
            if(p[j] == i){
                check = true;
                break;
            }
        }
        if(!check){
            break;
        }
    }
    if(check){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
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