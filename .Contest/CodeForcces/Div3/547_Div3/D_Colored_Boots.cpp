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
vector<vector<int>> l(27 , vector<int>());
vector<vector<int>> r(27 , vector<int>());
void solve()
{
    int n;
    cin >> n;
    string s , t;
    cin >> s >> t;
    int q1 = 0 , q2 = 0;
    fo(i , n){
        if(s[i] == '?'){
            l[26].pb(i + 1);
        }
        else{
            l[s[i] - 'a'].pb(i + 1);
        }

        if(t[i] == '?'){
            r[26].pb(i + 1);
        }
        else{
            r[t[i] - 'a'].pb(i + 1);
        }
    }
    vector<pii> ans;
    fo(i , 26){
        while(sz(l[i]) && sz(r[i])){
            ans.push_back({l[i].back() , r[i].back()});
            l[i].pop_back();
            r[i].pop_back();  
        }
    }
    int ptr = 0;
    while(sz(l[26])){
        while(sz(r[ptr]) == 0){
            ptr++;
        }
        ans.push_back({l[26].back() , r[ptr].back()});
        l[26].pop_back();
        r[ptr].pop_back();
    }
    ptr = 0;
    while(sz(r[26])){
        while(sz(l[ptr]) == 0){
            ptr++;
        }
        ans.push_back({l[ptr].back() , r[26].back() });
        r[26].pop_back();
        l[ptr].pop_back();
    }
    cout << sz(ans) << ln;
    for(pii i : ans){
        cout << i.first << ' ' << i.second << ln;
    }
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