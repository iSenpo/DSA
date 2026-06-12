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
    int c=0,e;
    int d=0;
    string s;
    cin >> s;
    fo(i,sz(s)){
        if(s[i] == '0'){
            e = i+1;
            for(int j=i;j<sz(s);j++){
                if(s[j]=='1'){
                    break;
                }
                d++;
            }
            break;
        }
        c++;
    }
    if(d>c){
        d = c;
    }
    if(c == sz(s)){
        cout << 1 << " " << sz(s) << " " << 1 << " " << 1 << endl;

    }else {
        cout << 1 << " " << sz(s) << " " << e-d << " " << sz(s)-d << endl;
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