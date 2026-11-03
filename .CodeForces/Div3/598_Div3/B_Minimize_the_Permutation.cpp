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
    vector<pii> b(n);
    fo(i , n){
        b[i] = {a[i] , i};
    }
    sort(all(b));
    int last = 0;
    vector<bool> mark(n -1 , false);
    fo(i , n){
        int ind = b[i].second;
        int k = ind;
        if(ind >= last){
            while(ind != last && !mark[ind - 1] && a[ind - 1] > a[ind]){
                swap(a[ind - 1] , a[ind]);
                mark[ind - 1] = true;
                ind--;
            }
        }
        last = k;
    }
    fo(i , n){
        cout << a[i] << ' ';
    }
    cout << ln;
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