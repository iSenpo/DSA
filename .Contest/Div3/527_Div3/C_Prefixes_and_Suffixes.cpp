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
    string s[m];
    vector<int> ind;
    fo(i , m){
         cin >> s[i];
         if(sz(s[i]) == n - 1){
            ind.pb(i);
         }
    }
    int pref , suff;
    if(s[ind[0]].substr(0 , n - 1) == s[ind[1]].substr(1 , n - 1)){
        pref = ind[1];
        suff = ind[0];
    }
    else{
        pref = ind[0];
        suff = ind[1];
    }
    vector<string> t;
    for(int i = 1 ; i < n - 1 ; i++){
        if(s[pref].substr(0 , i) == s[suff].substr(n - 1 - i , i)){
            t.push_back(s[pref].substr(0 , i));
        }
        else{
            break;
        }
    }
    int cntS = 0 , cntP = 0;
    string ans;
    for(int i = 0 ; i < m ; ++i){
        int size = sz(s[i]);
        if(s[pref].substr(0 , size) == s[i]){
            ans += 'P';
            cntP++;
        }
        else{
            ans += 'S';
            cntS++;
        }
    }
    if(cntS > cntP){
        int cnt = cntS - cntP;
        int i = 0;
        while(cnt--){
            for(int j = 0 ; j < sz(t) ; j++){
                if(t[j] == s[i] && ans[i] == 'S'){
                    cnt--;
                    ans[i] = 'P';
                    i++;
                    break;
                }
            }
            i++;
        }   
    }
    else if(cntP > cntS){
        int cnt = cntP - cntS;
        int i = 0;
        while(cnt--){
            for(int j = 0 ; j < sz(t) ; j++){
                if(t[j] == s[i] && ans[i] == 'P'){
                    cnt--;
                    ans[i] = 'S';
                    i++;
                    break;
                }
            }
        }
        i++;   
    }
    cout << ans << ln;
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