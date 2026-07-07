#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define pll pair<ll , ll>
#define ln '\n'
#define fo(i, n) for(int i = 0 ; i < n ; ++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
#define	set_dec(x) cout << fixed << setprecision(x);
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int MOD = 1e9 + 7;
const int N  = 2e5 + 10;
const int INF = 2e9 + 100;
const int MIN = -2e9 - 100;
//always check input!!!

void solve()
{
    int n , x;
    cin >> n >> x;
    vector<int> od , ev;
    fo(i , n){
        int a;
        cin >> a;
        if(a & 1){
            od.pb(a);
        }
        else{
            ev.pb(a);
        }
    }
    if(od.empty()){
        cout << "No\n";
        return;
    }
    if(x%2 == 0 && ev.empty()){
        cout << "No\n";
        return;
    }
    if(ev.size() >= x){
        cout << "Yes\n";
        return;
    }
    x -= ev.size();
    if(x%2 == 1){
        cout << "Yes\n";
    }
    else{
        if(x + 1 <= od.size()){
            cout << "Yes\n";
            return;
        }
        cout << "No\n";
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
