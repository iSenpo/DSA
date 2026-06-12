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
    int m = (2 * n) - 2;
    vector<string> a(m);
    fo(i , m) cin >> a[i];
    vector<string> v(all(a));
    for(int i = 0 ; i < m - 1 ; i++){
        for(int j = 0 ; j < m - i - 1 ; j++){
            if(sz(a[j]) > sz(a[j + 1])){
                swap(a[j] , a[j + 1]);
            }
        }
    }
    string t = a[m - 1] , s = a[m - 2];
    string str;
    string s1 , s2 , t1 , t2 , u1 , u2 , l1 , l2;
    s1 += a[0] + s;
    s2 += t + a[1];
    t1 += a[0] + t;
    t2 += s + a[1];
    u1 += a[1] + s;
    u2 += t + a[0];
    l1 += a[1] + t;
    l2 += s + a[0];
    if(s1 == s2){
        str = s1;
    }
    else if(t1 == t2){
        str = t1;
    }
    else if(u1 == u2){
        str = u1;
    }
    else{
        str = l1;
    }
    vector<char> ans;
    map<string , int> cnt;
    for(int i = 0 ; i < m ; i ++){
        int size = sz(v[i]);
        if(str.substr(0 , size) == v[i]){
            cnt[v[i]]++;
            if(cnt[v[i]]%2 == 0){
                ans.push_back('S');
                continue;
            }
            ans.push_back('P');
        }
        else{
            ans.push_back('S');
        }
    }    
    for(char c : ans){
        cout << c;
    }
    cout << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
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