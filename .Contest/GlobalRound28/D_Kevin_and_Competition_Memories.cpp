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
    int a[n] , b[m];
    fo(i , n) cin >> a[i];
    fo(i , m) cin >> b[i];
    int kevin = a[0];
    sort(a , a + n);
    sort(b , b + m);
    int ppl = n - 1;
    int count  = 0;
    vector<pii> v(m);
    for(int i = m - 1 ; i >= 0 ; --i){
        while(a[ppl] >= b[i]){
            count++;
            ppl--;
        }
        v[i] = make_pair(b[i] , count);
    }
    sort(all(v));
    int ptl = 0 , ptr = m - 1;
    for(int k = 1 ; k <= m ; ++k){
        ll sum = 0;
        for(int i = 0 ; i < m/k ; i++){ //?
            int rank = 0;
            for(int j = 0 ; j < k ; ++j){
                if(v[ptl].first <= kevin){
                    rank = 1; 
                    ptl++;
                }
                else{
                    rank = v[ptr].second + 1;
                    ptr--;
                }
            }
            sum += rank;
        }
        ptl = 0 ;
        ptr = m - 1;
        cout << sum << ' ';
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