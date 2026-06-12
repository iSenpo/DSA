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

const int ZN  = 1e5 + 500;
int a[ZN];
//always check input!!!

void solve()
{
    int n,fir,uni;
    cin >> n;
    int v[n][n-1];
    vector<int> b;
    fill(a,a+n+1,0);
    
    fo(i,n){
        fo(j,n-1){
            cin >> v[i][j];
        }
        a[v[i][0]]++;
    }
    fo(i,n+1){
        if(a[i] == 1){
            uni = i;
        }else if(a[i] == n-1){
            fir = i;
            
        }
    }
    b.pb(fir);
    fo(i,n){
        if(uni == v[i][0]){
            fo(j,n-1){
                b.pb(v[i][j]);
            }
        }
    }
    fo(i,sz(b)){
        cout << b[i] << " ";
    }
    cout << endl;


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