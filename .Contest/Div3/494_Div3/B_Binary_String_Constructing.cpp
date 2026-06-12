#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

const int N  = 1e5 + 500;

void solve()
{
    int a , b , x;
    cin >> a >> b >> x;
    string s = "";
    int temp = x + 1;
    bool start = a > b;
    while(temp--){
        if(start){
            s = s + "0";
            start = !start;
            a--;
        }
        else{
            s = s + "1";
            start = !start;
            b--;
        }
    }
    if (a > 0) {
        int pos0 = s.find('0');
        if (pos0 != string::npos) {
            s.insert(pos0 + 1, string(a, '0'));
            a = 0;
        } else {
            s += string(a, '0');
            a = 0;
        }
    }
    if (b > 0) {
        int pos1 = s.find('1');
        if (pos1 != string::npos) {
            s.insert(pos1 + 1, string(b, '1'));
            b = 0;
        } else {
            s += string(b, '1');
            b = 0;
        }
    }
    cout << s << ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*------------------------------------*/
    int t = 1;
    //t = in();
    while(t--){
        solve();
    }
    return 0;
}