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

ll cost(string s ,char ch){
    if(s.size() == 1){
        if(s[0] == ch){
            return 0;
        }
        else{
            return 1;
        }
    }
    int len = sz(s)/2;
    string t1 = s.substr(0 , len);
    string t2 = s.substr(len , len);
    int half1 = 0 , half2 = 0;
    for(int i = 0 ; i < len ; i++){
        if(s[i] != ch){
            half1++;
        }
    }
    for(int i = len ; i < 2 * len ; i++){
        if(s[i] != ch){
            half2++;
        }
    }
    return min(half1 + cost(t2 , ch + 1) , half2 + cost(t1 , ch + 1));
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << (ll)cost(s , 'a') << ln;
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