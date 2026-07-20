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
    fo(i , n) cin >> a[i];
    vector<int> tk;
    int ind2 = -1;
    tk.pb(a[0]);
    fo(i , n){
        if(a[i] != tk[0]){
            tk.pb(a[i]);
            ind2 = i;
            break;
        }
    }
    if(tk.size() != 2){
        cout << "NO\n";
        return;
    }
    vector<bool> seen(n + 1 , false);
    vector<pii> ans;
    fo(i , n){
        if(seen[i]){
            continue;
        }
        if(a[i] != tk[0] && a[i] != tk[1]){
            ans.push_back({i + 1 , 1});
            seen[0] = true;
            seen[i] = true;
        }
        else if(a[i] != tk[0]){
            ans.push_back({i + 1 , 1});
            seen[0] = true;
            seen[i] = true;
        }
        else if(a[i] != tk[1]){
            ans.push_back({i + 1 , ind2 + 1});
            seen[i] = true;
            seen[ind2] = true;
        }
    }
    cout << "YES\n";
    for(pii i : ans){
        cout << i.first << ' ' << i.second << ln; 
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