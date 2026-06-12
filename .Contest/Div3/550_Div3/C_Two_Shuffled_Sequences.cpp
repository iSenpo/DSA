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

const int INF  = 1e7 + 677667676;
//always check input!!!
bool check(int a[], int n){
    fo(i , n - 2){
        if(a[i] == a[i + 1] && a[i + 1] == a[i + 2]){
            return false;
        }
    } 
    return true;
}
void solve()
{
    int n;
    cin >> n;
    int a[n + 1];
    fo(i , n) cin >> a[i];
    a[n] = INF;
    sort(a , a + n);
    if(!check(a , n)){
        cout << "NO" << ln;
        return;
    }
    vector<int> inc , dec;
    fo(i , n){
        if(a[i] == a[i + 1]){
            dec.push_back(a[i + 1]);
            inc.pb(a[i]);
            i++;
        }
        else{
            inc.pb(a[i]);
        }
    }
    sort(all(inc));
    sort(all(dec));
    reverse(all(dec));
    cout << "YES\n";
    cout << sz(inc) << ln;
    for(int i : inc){
        cout << i << ' ';
    }
    cout << ln;
    cout << sz(dec) << ln;
    for(int i : dec){
        cout << i << ' ' ;
    }
    cout << ln;
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