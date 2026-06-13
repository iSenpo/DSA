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
    int n , x , y;
    cin >> n >> x >> y;
    int a[n] , Min = INF , MinInd = -1;
    fo(i , n) cin >> a[i];
    vector<int> p2 , p , pt;
    for(int i = x ; i < y ; i++){
        if(a[i] < Min){
            Min = a[i];
            MinInd = i;
        }
    }
    for(int i = MinInd ; i < y ; i++){
        p2.push_back(a[i]);
    }
    for(int i = x ; i < MinInd ; i++){
        p2.push_back(a[i]);
    }
    for(int i = 0 ; i < x ; i++){
            p.push_back(a[i]);
        }   
    for(int i = y ; i < n ; i++){
        p.push_back(a[i]);
    }
    pt = p;
    int j = p.size();
    for(int i = 0 ; i < p.size() ; i++){
        if(p[i] > p2[0]){
            j = i;
            break;
        }
    }
    for(int i = 0 ; i < j ; i++){
        cout << pt[i] << ' ';
    }
    for(int i : p2){
        cout << i << ' ';
    }
    for(int i = j ; i < pt.size() ; i++){
        cout << pt[i] << ' ';
    }
    cout << ln;
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
