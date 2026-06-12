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
    int a[2 * n];
    set<int> st;
    map<int , int> cnt;
    fo(i , 2 * n){
         cin >> a[i];
         st.insert(a[i]);
         cnt[a[i]]++;
    }
    vector<int> v(all(st));
    int zoj = 0 , zojj = 0, fard = 0 , fard1 = 0;
    fo(i , v.size()){
        if(cnt[v[i]]%2 == 0){
           zoj++;
        }
        else{
            fard++;
        }
    }
    ll d1 , d2 = 0;
    if((zoj % 2) == (n % 2)){
        d1 = zoj;
    }
    else{
        d1 = zoj - 1;
    }
    d1 = max (d1 , 0LL);
    if(fard > 0){
        if(zoj % 2 == (n-1) % 2){
            d2 = zoj;
        }
        else{
            d2 = zoj - 1;
        }
        d2 = max(d2 , 0LL);
    }
    ll ans = max(d1 , d2);
    cout << fard + 2*ans << ln;
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