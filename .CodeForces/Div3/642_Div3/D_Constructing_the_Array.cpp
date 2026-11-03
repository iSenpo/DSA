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

struct cmp{
    bool operator()(const pair<int , int> &a, const pair<int , int> &b) const{
        int lena = a.second - a.first + 1;
        int lenb = b.second - b.first + 1;
        if(lena == lenb){
            return a.first < b.first;
        }
        return lena > lenb;
    }
};
void solve()
{
    int n;
    cin >> n;
    set<pair<int , int> , cmp> st;
    st.insert({0 , n - 1});
    vector<int> ans(n);
    for(int i = 1 ; i <= n ; i++){
        pii x = *st.begin();
        st.erase(st.begin());
        int ind = (x.second + x.first)/2;
        ans[ind] = i;
        if(x.first < ind){
            st.insert({x.first , ind - 1});
        }
        if(x.second > ind){
            st.insert({ind + 1 , x.second});
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << ans[i] << ' ';
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