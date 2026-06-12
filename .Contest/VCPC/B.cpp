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

const string b = "FBI";

void solve()
{
    string s[5];
    fo(i ,5) cin >> s[i];
    vector<int> ans;
    fo(i , 5){
        int t = sz(s[i]);
        for(int j = 0 ; j < t - 2 ; j++){
            if(s[i].substr(j , 3) == b){
                ans.push_back(i + 1);
                break;
            }
        }
    }
    if(ans.size() == 0){
        cout << "HE GOT AWAY!\n";
        return;
    }
    else{
        for(int i : ans){
            cout << i << ' ';
        }
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