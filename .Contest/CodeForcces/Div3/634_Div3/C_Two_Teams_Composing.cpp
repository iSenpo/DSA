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
    unordered_set<int> st;
    fo(i , n){
        cin >> a[i];
        cnt[a[i]]++;
        st.insert(a[i]);
    }
    if(n < 2){
        cout << 0 << ln;
        return;
    }
    vector<int> v;
    int fix = st.size();
    fo(i , fix){
        int x = *st.begin();
        st.erase(st.begin());
        v.push_back(cnt[x]);
    }
    sort(all(v));
    if(v.size() < v[fix -1]){
        cout << v.size() << ln;
        return;
    }
    else{
        cout << max(min((int)v.size() - 1 , v[fix - 1]) , 1) << ln;
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